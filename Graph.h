#ifndef GRAPH_H_
#define GRAPH_H_

#include "City.h"


class Graph
{
public:
    Graph( City **adjList, int numVertices);
    ~Graph();
    void dijkstra( int source );
    void printShortestPath( string source, string destination);
    int getCityIdByName( string name);
    void printCurrDistAndPrevs();

private:
    City **adjList;
    int numVertices;

    //the prev. cities and distance values arrays according to the last given source city
    int *prevs;
    int *distances;
};

#endif
