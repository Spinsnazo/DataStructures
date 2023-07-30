#ifndef MATRIXADJACENCY_H
#define MATRIXADJACENCY_H

#include <iostream>
#include <string>
#include <random>
#include <time.h>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include "WEdge.h"

#define MAX_WEIGHT 100

/**
 * A class to store a weighted directed graph using an adjacency matrix.
*/
class MatrixAdjacency
{
    public:
        // Create an empty size x size matrix representing a graph
        MatrixAdjacency(int size);
        // Create a connected graph with siz nodes and edge edges
        MatrixAdjacency(int size, int edge);
        // Destroy an object
        ~MatrixAdjacency();
        // Print adjacency list
        void printEdges();
        // Print all edges coming out from a given node
        std::string getNode(int i);
        // Set a specific edge (weight)
        void setEdge(int src, int dst, int w);
        // Zero all edges
        void zeroEdges();
        // Find a MST (minimum spanning tree) starting from the node
        std::string MST(int node);
        // Perform the breadth-first search algorithm
        std::string BFS(int node);
        // Perform the depth-first search algorithm
        std::string DFS(int node);
    private:
        int** matrix;
        int size;
};

#endif // MATRIXADJACENCY_H
