#ifndef HEAPPTR_H
#define HEAPPTR_H

#include "HeapNode.h"
#include <iostream>
#include <queue>


class HeapPtr
{
    public:
        HeapPtr();
        ~HeapPtr();
        void add(int n);
        int del(HeapNode *node);
        void heapify_up(HeapNode *node);
        void heapify_down(HeapNode *node);
        HeapNode* find_last();
        void print_heap();
        static void heapify_sort(int arr[], int size_arr);
    private:
        HeapNode* root;
        int size;
};

#endif // HEAPPTR_H
