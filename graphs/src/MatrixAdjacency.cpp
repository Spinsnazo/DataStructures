#include "MatrixAdjacency.h"

MatrixAdjacency::MatrixAdjacency(int siz)
{
    size = siz;
    matrix = new int*[size];
    for(int i=0; i<size; i++)
    {
        matrix[i] = new int [size];
        for(int j=0; j<size; j++)
            matrix[i][j] = 0;
    }
}

MatrixAdjacency::MatrixAdjacency(int siz, int edge): MatrixAdjacency(siz)
{
    // Generate a random spanning tree first

    std::vector<int> available = {};

    for(int i=1; i<size; i++)
    {
        available.push_back(i);
    }

    int start_node = 0;
    int max_edge_num = size * size - size;

    int add_edges_total = 0, add_edges_node = 0;   // edge - (size - 1) = edge - size +1

    if(edge < max_edge_num)
    {
        add_edges_node =  (edge - size + 1) / size;           // Edges that we have to add to the existing ones per each node of the spanning tree
        add_edges_total =  (edge - size + 1);                 // Total number of edges that we have to add to the existing ones
    }

    int extra_edges = 0;  // Number of edges added to the tree

    int end_node = 0;

    while(available.size()!=0)
    {
        int end_node_index = rand()%available.size();
        end_node = available[end_node_index];
        available.erase(available.begin() + end_node_index);
        matrix[start_node][end_node] = rand()%(MAX_WEIGHT*2)+1;

        /*
        Firstly, we need to generate a spanning tree consisting of n-1 edges for n nodes.
        We add extra edges to each node so that there are 'edge' of them.

        Add extra edges to bring the total number to 'edge'
        */

        int extra_edges_node = 0;
        std::set<int> extra_visited;
        while(extra_edges_node < add_edges_node)
        {
            int end_extra_node = rand()%size;
            if(end_extra_node!=start_node && end_extra_node!=end_node && !extra_visited.count(end_extra_node))
            {
                extra_edges_node++;
                extra_edges++;
                matrix[start_node][end_extra_node] = rand()%MAX_WEIGHT+1;
                extra_visited.insert(end_extra_node);
            }
        }
        start_node = end_node;
    }

    /*
    Add edges to the end node

    The quotient in 'add_edges_node' may not be an integer so we add more edges to the last
    node of the tree to make sure there are 'edge' of them.
    */

    std::set<int>add_last_node;

    while(extra_edges<add_edges_total)
    {
        int extra_end = rand()%size;
        if(extra_end!=end_node && !add_last_node.count(extra_end))
        {
            extra_edges++;
            matrix[end_node][extra_end] = rand()%MAX_WEIGHT+1;
            add_last_node.insert(extra_end);
        }
    }
}

MatrixAdjacency::~MatrixAdjacency()
{
    for(int i=0; i<size; i++)
    {
        delete [] matrix[i];
    }
    delete [] matrix;
}

void MatrixAdjacency::zeroEdges()
{
    for(int i=0; i<size; i++)
        for(int j=0; j<size; j++)
            matrix[i][j] = 0;
}

void MatrixAdjacency::printEdges()
{
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            std::cout<<matrix[i][j]<<"\t";
        }
        std::cout<<"\n";
    }
}

std::string MatrixAdjacency::getNode(int n)
{
    std::string result;
    result += "N: " + std::to_string(n) + " E: ";
    for(int j=0; j<size; j++)
    {
        if(matrix[n][j]!=0)
        {
            result += "(" + std::to_string(j) + ", " + std::to_string(matrix[n][j]) + "), ";
        }
    }
    return result;
}

void MatrixAdjacency::setEdge(int src, int dst, int w)
{
    if(src >= 0 && src < size && dst >= 0 && dst < size)
        matrix[src][dst] = w;
}

// Unpredictable results for node not equal to 0
std::string MatrixAdjacency::MST(int node)
{
    if(node < 0 || node >= size) return std::string("");

    std::set<int>visited;
    visited.insert(node);
    std::vector<WEdge> mst;
    int current_node = node;
    std::priority_queue<WEdge> edges;

    // An algorithm with a priority queue - like in 'AdjacencyList'

    while(visited.size() < (unsigned)size)
    {
        for(int i=0; i<size; i++)
        {
            if(matrix[current_node][i] != 0)
            {
                edges.push(WEdge(current_node, i, matrix[current_node][i]));
            }
        }

        WEdge current_edge;

        do
        {
            current_edge = edges.top();
            edges.pop();
            if(visited.count(current_edge.getDst())==0)
            {
                current_node = current_edge.getDst();
                visited.insert(current_node);
                mst.push_back(current_edge);
                break;
            }
        }
        while(!edges.empty());

    }

    std::string result = "MST: ";
    for(unsigned i=0; i<mst.size(); i++)
    {
        result += mst[i].toString() + ", ";
    }

    return result;
}

std::string MatrixAdjacency::BFS(int node)
{
    if(node < 0 || node >= size) return std::string("");

    std::queue<WEdge> que;
    std::string result = "BFS: ";
    std::set<int> visited;
    visited.insert(node);
    int current_node = node;

    do
    {
        for(int i=0; i<size; i++)
        {
            if(matrix[current_node][i]!=0)
            {
                que.push(WEdge(current_node, i, matrix[current_node][i]));
            }
        }

        WEdge cur;

        while(!que.empty())
        {
            WEdge cur = que.front();
            que.pop();
            if(visited.count(cur.getDst())==0)
            {
                result += cur.toString() + ", ";
                visited.insert(cur.getDst());
                current_node = cur.getDst();
                break;
            }
        }
    }
    while(!que.empty());

    return result;
}

// It's the same way as in the BFS algorithm but the stack is used instead of the queue
std::string MatrixAdjacency::DFS(int node)
{
    if(node < 0 || node >= size) return std::string("");

    std::stack<WEdge> st;
    std::string result = "DFS: ";
    std::set<int> visited;
    visited.insert(node);
    int current_node = node;
    do
    {
        for(int i=0; i<size; i++)
        {
            if(matrix[current_node][i]!=0)
            {
                st.push(WEdge(current_node, i, matrix[current_node][i]));
            }
        }
        WEdge cur;
        while(!st.empty())
        {
            WEdge cur = st.top();
            st.pop();
            if(visited.count(cur.getDst())==0)
            {
                result += cur.toString() + ", ";
                visited.insert(cur.getDst());
                current_node = cur.getDst();
                break;
            }
        }
    }
    while(!st.empty());

    return result;
}
