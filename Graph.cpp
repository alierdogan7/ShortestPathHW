#include <iostream>
#include <cstdlib>
#include <string>
#include <queue>
#include <stack>
using namespace std;

#include "Graph.h"
#include "City.h"

/*

Given a graph, G, with edges E of the form (v1, v2) and vertices V, and a
source vertex, s

dist : array of distances from the source to each vertex
prev : array of pointers to preceding vertices
i    : loop index
F    : list of finished vertices
U    : list or heap unfinished vertices

/* Initialization: set every distance to INFINITY until we discover a path
for i = 0 to |V| - 1
    dist[i] = INFINITY
    prev[i] = NULL
end

/* The distance from the source to the source is defined to be zero
dist[s] = 0

/* This loop corresponds to sending out the explorers walking the paths, where
 * the step of picking "the vertex, v, with the shortest path to s" corresponds
 * to an explorer arriving at an unexplored vertex

while(F is missing a vertex)
   pick the vertex, v, in U with the shortest path to s
   add v to F
   for each edge of v, (v1, v2)
        /* The next step is sometimes given the confusing name "relaxation"
        if(dist[v1] + length(v1, v2) < dist[v2])
            dist[v2] = dist[v1] + length(v1, v2)
            prev[v2] = v1
            possibly update U, depending on implementation
        end if
    end for
end while
*/


/*struct minHeapComparator {
    bool operator()(const int& a, const int& b) { return a > b; }
};*/

Graph::Graph( City **adjList, int numVertices)
{
    this->adjList = adjList;
    this->numVertices = numVertices;
}

Graph::~Graph()
{
    for(int i = 0; i < this->numVertices; i++)
        delete this->adjList[i];

    delete []this->adjList;
}

int Graph::getCityIdByName( string name)
{
    for( int i = 0; i < this->numVertices; i++)
        if( name.compare( (this->adjList[i])->getName() ) )
            return (this->adjList[i])->getId();
    return -1;
}

void Graph::printShortestPath( string source, string destination)
{
    int sourceIndex, destIndex;
    sourceIndex = this->getCityIdByName( source );
    destIndex = this->getCityIdByName( destination );

    //start from the destination, trace the path towards the source using a STACK
    stack<int> path;

    int currIndex = destIndex;
    path.push( destIndex ); //push the dest.
    while( this->distances[currIndex] > 0 && this->prevs[currIndex] != -1)
    {
        path.push( this->prevs[currIndex] ); //push the prev. val
        currIndex = this->prevs[currIndex]; // update the curr. index
    }
    path.push( currIndex ); //push the source

    cout << "The shortest path from " << source << " to " << destination << " is " << path.size() << " along cities and it's like below: " << endl;
    while( !path.empty() )
    {
        cout << (this->adjList[ path.top() ])->getName() << endl;
        path.pop();
    }
    cout << endl;

}

//it loads the distances and prevs arrays of the Graph object according to the source city
void Graph::dijkstra( int source )
{
    //vector<int> distances(size); dynamicly allocated no need to deallocation

    //priority_queue<int, vector<int>, minHeapComparator> tmpDistances;
    bool isDone = false;
    this->prevs = new int[this->numVertices];
    this->distances = new int[this->numVertices];

    // the completed paths array is parallel with the distances array and it consists of 1's and 0's as flags
    bool *completedPaths = new bool[this->numVertices];
    for(int i = 0; i < this->numVertices; i++)
        completedPaths[i] = false; //initialize all of them with 0's

    completedPaths[source] = true; //the source to source path is considered as completed

    //initialize the distances and prev. values of nodes
    for(int i = 0; i < this->numVertices; i++)
    {
        prevs[i] = -1; // prev. is null

        this->distances[i] = 9999;
        (i == source) && ( this->distances[i] = 0); //initialize the source's distance with 0

    }

    //debugging
    this->printCurrDistAndPrevs();

    while(!isDone)
    {
        //choose the min. distance from unfinished paths
        //since the 0th elem. is source and the distance is always zero, we start from 1st element
        (source == 0)int minIndex = 1;
        for(int i = 0; i < numVertices; i++)
        {
            //if that path is completed, just ignore
            if( completedPaths[i] )
                continue;

            if( this->distances[i] <= this->distances[minIndex] )
                minIndex = i; // we have a new min. distance
        }

        //according to the Dijkstra's algorithm, the chosen one with min. distance is a completed path from now on.
        completedPaths[minIndex] = true;

        City *tmpCity = this->adjList[minIndex];
        for( int i = 0; i < tmpCity->getDegree(); i++)
        {
            //if the current city's distance + 1 is less than the curr. distance of its neighbor, do relaxation
            if (this->distances[ tmpCity->getId() ] + 1 < this->distances[ tmpCity->getNeighborIds()[i] ] )
            {
                this->prevs[ tmpCity->getNeighborIds()[i] ] = tmpCity->getId();
                this->distances[ tmpCity->getNeighborIds()[i] ] = this->distances[ tmpCity->getId() ] + 1;
            }

            this->printCurrDistAndPrevs();
        }

        // if there is even a single path which is not completed so far, continue to process
        isDone = true;
        cout << "\n------\ncompletedPaths: ";
        for(int i = 0; i < this->numVertices; i++)
        {
            cout << (completedPaths[i] ? "1 " : "0 ");
            if( !completedPaths[i] )
            {
                isDone = false;
                break;
            }
        }
        cout << "\n" << endl;

    }

    delete []completedPaths;
}

void Graph::printCurrDistAndPrevs()
{
    cout << "Current distances and prevs.: ";
    for(int i = 0; i < this->numVertices; i++)
        cout << "[" << this->distances[i] << "," << this->prevs[i] << "] ";
    cout << endl;
}
