#ifndef HEAPNODE_H
#define HEAPNODE_H


struct HeapNode
{
    HeapNode *parent;
    HeapNode *left_child;
    HeapNode *right_child;
    int value;
};

#endif // HEAPNODE_H
