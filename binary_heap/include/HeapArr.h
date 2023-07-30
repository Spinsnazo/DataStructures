#ifndef HEAPARR_H
#define HEAPARR_H

#include <iostream>

/**
 * An array-based implementation of a binary heap.
*/
class HeapArr
{
    public:
        // Construct a heap of capacity of 10
        HeapArr();
        // Destroy an object
        ~HeapArr();
        // Construct a heap of capacity 'size'
        HeapArr(int size);
        // Add an integer 'element' to a heap
        void add(int element);
        // Delete an element with an index 'index' in the heap's array
        int del(int index);
        // Heapify up
        void heapify_up(int index);
        // Heapify down
        void heapify_down(int index);
        // Output the heap in an array order
        void print_heap();
        // Perform heap sort on an array 'arr' of size 'size_arr'
        static void heapify_sort(int arr[], int size_arr);
    private:
        int *heap;
        int elements;
        int size;
};

#endif // HEAPARR_H
