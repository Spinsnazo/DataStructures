#ifndef WEDGE_H
#define WEDGE_H

#include <string>

/**
 *  A class used to store an edge with weight.
*/
class WEdge
{
    public:
        WEdge();
        WEdge(int source, int dest, int weight);
        int getSrc();
        int getDst();
        int getW();
        std::string toString();
        bool operator<(const WEdge& sec) const;
    private:
        int src;
        int dst;
        int w;
};

#endif // WEDGE_H
