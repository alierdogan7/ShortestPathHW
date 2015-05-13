#include <iostream>
#include <cstdlib>
#include <string>
#include <queue>
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

struct minHeapComparator {
    bool operator()(const int& a, const int& b) { return a > b; }
};

void Graph::dijkstra( int source, int*& distances, int*& prevs)
{
    //vector<int> distances(size); dynamicly allocated no need to deallocation

    //priority_queue<int, vector<int>, minHeapComparator> tmpDistances;
    bool isDone = false;
    prevs = new int[this->numVertices];
    distances = new int[this->numVertices];

    // the completed paths array is parallel with the distances array and it consists of 1's and 0's as flags
    int *completedPaths = new int[this->numVertices];
    for(int i = 0; i < this->numVertices; i++)
        completedPaths[i] = 0; //initialize all of them with 0's

    //initialize the distances and prev. values of nodes
    for(int i = 0; i < this->numVertices; i++)
    {
        prevs[i] = -1; // prev. is null

        distances[i] = 9999;
        (i == source) && ( distances[i] = 0);

    }

    while(!isDone)
    {
        //choose the min. distance from unfinished paths
        int minIndex = 0;
        for(int i = 0; i < numVertices; i++)
        {
            //if that path is completed, just ignore
            if( completedPaths[i] )
                continue;

            if( distances[i] < distances[minIndex] )
                minIndex = i; // we have a new min. distance
        }

        City *tmpCity = this->adjList[minIndex];
        for( int i = 0; i < tmpCity->getDegree(); i++)
        {
            if ( distances[ tmpCity->neighborIds[i] ] < distances[ tmpCity->getId() ] + 1 )
            {

            }
        }

    }



}
