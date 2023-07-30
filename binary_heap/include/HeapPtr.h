#ifndef HEAPPTR_H
#define HEAPPTR_H

#include "HeapNode.h"
#include <iostream>
#include <queue>

/**
 * A pointer-based implementation of a binary heap.
*/
class HeapPtr
{
    public:
        // Construct a heap
        HeapPtr();
        // Destroy an object
        ~HeapPtr();
        // Add an integer 'element' to a heap
        void add(int n);
        // Delete an element pointed to by 'node' pointer
        int del(HeapNode *node);
        // Heapify up
        void heapify_up(HeapNode *node);
        // Heapify down
        void heapify_down(HeapNode *node);
        // Find a pointer to the last element in a heap
        HeapNode* find_last();
        // Output the heap in an array order
        void print_heap();
        // Perform heap sort on an array 'arr' of size 'size_arr'
        static void heapify_sort(int arr[], int size_arr);
    private:
        HeapNode* root;
        int size;
};

#endif // HEAPPTR_H
