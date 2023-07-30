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

/**
 * A class to store a weighted directed graph using an adjacency list.
*/
class AdjacencyList
{
    public:
        // Create an empty size x size matrix representing a graph
        AdjacencyList(int size);
        // Create a connected graph with siz nodes and edge edges                               
        AdjacencyList(int size, int edge);
        // Print adjacency list             
        void printEdges();
        // Print all edges coming out from a given node                                          
        std::string getNode(unsigned i);
        // Set a specific edge (weight)       
        void setEdge(unsigned src, unsigned dst, unsigned w);
        // Zero all edges    
        void zeroEdges();
        // Find a MST (minimum spanning tree) starting from the node                    
        std::string MST(unsigned node);
        // Perform the breadth-first search algorithm                           
        std::string BFS(unsigned node);
        // Perform the depth-first search algorithm                             
        std::string DFS(unsigned node);
    private:
        // First number in a pair - destination, second - weight
        std::vector<std::vector<std::pair<int,int>>> nodes;
};

#endif // ADJACENCYLIST_H
