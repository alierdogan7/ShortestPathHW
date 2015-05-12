#ifndef GRAPH_H_
#define GRAPH_H_

#include "City.h"


class Graph
{
public:
    Graph();
    ~Graph();
    void dijkstra( Graph& graph, int source, int*& distances, int*& prevs);

private:
    City *adjList;
    int numVertices;
};

#endif
