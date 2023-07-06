#include <iostream>
#include "MatrixAdjacency.h"
#include "AdjacencyList.h"
#include <chrono>
#include <iomanip>


// Number of nodes and edges for comparison tests between the adjacency matrix and adjacency list
#define NODES 10000
#define EDGES 40000
//#define PRINTING

int main()
{
    srand(1212);
    MatrixAdjacency m(NODES, EDGES);
    #ifdef PRINTING
    m.printEdges();
    std::cout<<"\n";
    std::cout<<m.getNode(5)<<"\n";
    std::cout<<"\n";
    std::cout<<m.MST(0)<<"\n";
    std::cout<<m.BFS(0)<<"\n";
    std::cout<<m.DFS(0)<<"\n";
    std::cout<<"\n\n";
    #endif
    #ifndef PRINTING
    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
	auto diff = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    start = std::chrono::high_resolution_clock::now();
    m.MST(0);
    end = std::chrono::high_resolution_clock::now();
    diff = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    long long mtx_mst = diff;
    start = std::chrono::high_resolution_clock::now();
    m.BFS(0);
    end = std::chrono::high_resolution_clock::now();
    diff = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    long long mtx_bfs = diff;
    start = std::chrono::high_resolution_clock::now();
    m.DFS(0);
    end = std::chrono::high_resolution_clock::now();
    diff = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    long long mtx_dfs = diff;
    end = std::chrono::high_resolution_clock::now();
    diff = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    std::cout<<"Adjacency Matrix MST/BFS/DFS: "<<std::setw(10)<<mtx_mst<<" ns "<<"\t"<<mtx_bfs<<" ns\t"<<mtx_dfs<<" ns.\n";
    #endif


    srand(1212);
    AdjacencyList al(NODES, EDGES);
    #ifdef PRINTING
    al.printEdges();
    std::cout<<"\n";
    std::cout<<al.getNode(5)<<"\n";
    std::cout<<"\n";
    std::cout<<al.MST(0)<<"\n";
    std::cout<<al.BFS(0)<<"\n";
    std::cout<<al.DFS(0)<<"\n";
    #endif
    #ifndef PRINTING
    start = std::chrono::high_resolution_clock::now();
    al.MST(0);
    end = std::chrono::high_resolution_clock::now();
    diff = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    long long ls_mst = diff;
    start = std::chrono::high_resolution_clock::now();
    al.BFS(0);
    end = std::chrono::high_resolution_clock::now();
    diff = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    long long ls_bfs = diff;
    start = std::chrono::high_resolution_clock::now();
    al.DFS(0);
    end = std::chrono::high_resolution_clock::now();
    diff = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    long long ls_dfs = diff;
    end = std::chrono::high_resolution_clock::now();
    diff = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    std::cout<<"Adjacency List MST/BFS/DFS: "<<std::setw(10)<<ls_mst<<" ns "<<"\t"<<ls_bfs<<" ns\t"<<ls_dfs<<" ns.\n";
    std::cout<<"Difference Matrix-AdjacencyList "<<std::setw(10)<<mtx_mst-ls_mst<<" ns "<<"\t"<<mtx_bfs-ls_bfs<<" ns\t"<<mtx_dfs-ls_dfs<<" ns.\n";
    #endif
    return 0;
}
