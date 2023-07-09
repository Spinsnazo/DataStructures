#ifndef HEAPARR_H
#define HEAPARR_H

#include <iostream>


class HeapArr
{
    public:
        HeapArr();
        ~HeapArr();
        HeapArr(int size);
        void add(int element);
        int del(int index);
        void heapify_up(int index);
        void heapify_down(int index);
        void print_heap();
        static void heapify_sort(int arr[], int size_arr);
    private:
        int *heap;
        int elements;
        int size;
};

#endif // HEAPARR_H
