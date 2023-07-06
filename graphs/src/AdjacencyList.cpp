#include "AdjacencyList.h"

AdjacencyList::AdjacencyList(int size)
{
    nodes.resize(size);
}

AdjacencyList::AdjacencyList(int size, int edge):AdjacencyList(size)
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
        nodes[start_node].push_back(std::make_pair(end_node, rand()%(MAX_WEIGHT*2)+1));

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
                nodes[start_node].push_back(std::make_pair(end_extra_node, rand()%MAX_WEIGHT+1));
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
            nodes[end_node].push_back(std::make_pair(extra_end, rand()%MAX_WEIGHT+1));
            add_last_node.insert(extra_end);
        }
    }
}

void AdjacencyList::printEdges()
{
    for(unsigned i=0; i<nodes.size(); i++)
    {
        std::cout<<"N:"<<i<<": ";
        for(unsigned j=0; j<nodes[i].size(); j++)
        {
            std::cout<<"("<<nodes[i][j].first<<","<<nodes[i][j].second<<"), ";
        }
        std::cout<<"\n";
    }
}

std::string AdjacencyList::getNode(unsigned i){
    if(i<0||i>=nodes.size()) return std::string("");
    std::string result = "N: " + std::to_string(i) + " E: ";
    for(unsigned j=0; j<nodes[i].size(); j++){
        result+= "(" + std::to_string(nodes[i][j].first) + "," + std::to_string(nodes[i][j].second) + "), ";
    }
    return result;
}

void AdjacencyList::zeroEdges(){
    for(unsigned i=0; i<nodes.size(); i++){
        nodes[i].clear();
    }
}

void AdjacencyList::setEdge(unsigned src, unsigned dst, unsigned w){
    if(src<0||src>=nodes.size()) return;
    // Check if the edge already exists
    for(unsigned i=0; i<nodes[src].size(); i++){
        if((unsigned)nodes[src][i].first==dst){
            nodes[src][i].second = w;
            return;
        }
    }
    nodes[src].push_back(std::make_pair(dst, w));
}

// Unpredictable results for node not equal to 0
std::string AdjacencyList::MST(unsigned node)
{
    if(node < 0 || node >= nodes.size()) return std::string("");

    std::set<int>visited;
    visited.insert(node);
    std::vector<WEdge> mst;
    int current_node = node;
    std::priority_queue<WEdge> edges;

    while(visited.size() < nodes.size())
    {
        for(unsigned i=0; i<nodes[current_node].size(); i++)
        {
            edges.push(WEdge(current_node, nodes[current_node][i].first, nodes[current_node][i].second));
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

std::string AdjacencyList::BFS(unsigned node)
{
    if(node < 0 || node >= nodes.size()) return std::string("");

    std::queue<WEdge> que;
    std::string result = "BFS: ";
    std::set<int> visited;
    visited.insert(node);
    int current_node = node;

    do
    {
        for(unsigned i=0; i<nodes[current_node].size(); i++)
        {
            que.push(WEdge(current_node, nodes[current_node][i].first, nodes[current_node][i].second));
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

std::string AdjacencyList::DFS(unsigned node)
{
    if(node < 0 || node >= nodes.size()) return std::string("");

    std::stack<WEdge> st;
    std::string result = "DFS: ";
    std::set<int> visited;
    visited.insert(node);
    int current_node = node;
    do
    {
        for(unsigned i=0; i<nodes[current_node].size(); i++)
        {
            st.push(WEdge(current_node, nodes[current_node][i].first, nodes[current_node][i].second));
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
