#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

#include <vector>
#include <utility>
#include <random>
#include <set>
#include <queue>
#include <iostream>
#include <string>
#include <stack>
#include "WEdge.h"

#define MAX_WEIGHT 100

class AdjacencyList
{
    public:
        AdjacencyList(int size);                                    // Creates an empty size x size matrix representing a graph
        AdjacencyList(int size, int edge);                          // Creates a connected graph with siz nodes and edge edges
        void printEdges();                                          // Print the entire adjacency list
        std::string getNode(unsigned i);                            // Print all edges coming out from a given node
        void setEdge(unsigned src, unsigned dst, unsigned w);       // Set a specific edge (weight)
        void zeroEdges();                                           // Zero all edges
        std::string MST(unsigned node);                             // Find a MST (minimum spanning tree) starting from the node
        std::string BFS(unsigned node);                             // Perform the breadth-first search algorithm
        std::string DFS(unsigned node);                             // Perform the depth-first search algorithm
    private:
        std::vector<std::vector<std::pair<int,int>>> nodes;         // First number in a pair - destination, second - weight
};

#endif // ADJACENCYLIST_H
