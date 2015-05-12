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

void Graph::dijkstra( Graph& graph, int source, int*& distances, int*& prevs)
{
    //vector<int> distances(size); dynamicly allocated no need to deallocation

    priority_queue<int, vector<int>, minHeapComparator> tmpDistances;
    prevs = new int[this->numVertices];

    /*tmp.push(3);
    tmp.push(25);
    tmp.push(12);
    tmp.push(9);
    tmp.push(41);
    tmp.push(55);
    tmp.push(56);
    tmp.push(1);

    while(!tmp.empty())
    {
        cout << tmp.top() << endl;
        tmp.pop();
    }*/

}
