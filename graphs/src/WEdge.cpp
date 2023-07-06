#include "WEdge.h"

WEdge::WEdge(){}

WEdge::WEdge(int source, int dest, int weight)
{
    src = source;
    dst = dest;
    w = weight;
}

int WEdge::getSrc(){
    return src;
}

int WEdge::getDst(){
    return dst;
}

int WEdge::getW(){
    return w;
}

std::string WEdge::toString(){
    return std::string("(") + std::to_string(src) + "," +
    std::to_string(dst) + "," + std::to_string(w) + ")";
}

bool WEdge::operator<(const WEdge& sec) const{
    return w > sec.w;
}
