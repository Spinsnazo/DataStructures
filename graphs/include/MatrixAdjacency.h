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

class MatrixAdjacency
{
    public:
        MatrixAdjacency(int siz);              // Creates an empty size x size matrix representing a graph
        MatrixAdjacency(int siz, int edge);    // Creates a connected graph with siz nodes and edge edges
        ~MatrixAdjacency();                    // Deallocates memory
        void zeroEdges();                      // Zeroes all edges
        void printEdges();                     // Print all edges in a matrix form onto a screen
        std::string getNode(int n);            // Get a list of all edges coming out of a given node
        void setEdge(int src, int dst, int w); // Set an edge between src and dst with weight of w
        std::string MST(int node);             // Find a MST (minimum spanning tree) starting from the node
        std::string BFS(int node);             // Perform the breadth-first search algorithm
        std::string DFS(int node);             // Perform the depth-first search algorithm
    private:
        int** matrix;
        int size;
};

#endif // MATRIXADJACENCY_H
