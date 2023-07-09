#include <iostream>
#include <iomanip>
#include "HeapPtr.h"
#include "HeapArr.h"
#include <random>
#include <time.h>
#include <chrono>
#include <algorithm>
#include <vector>

#define SIZE 15000
//#define PRINTING
#define POINTERS
//#define OTHER_TESTS


int main()
{
#ifdef OTHER_TESTS
    HeapPtr heap;
    heap.add(1);
    heap.add(6);
    heap.add(7);
    heap.add(2);
    heap.print_heap();
    std::cout<<heap.find_last()->value<<"\n";
    heap.add(1);
    heap.add(20);
    heap.add(10);
    heap.add(-5);
    heap.add(8);
    heap.add(9);
    heap.print_heap();
    std::cout<<heap.find_last()->value<<"\n";
    heap.add(1);
    heap.add(1);
    heap.add(50);
    heap.add(50);
    HeapNode* cur = heap.find_last();
    std::cout<<"value: "<<cur->value<<"\n";
    heap.add(50);
    heap.add(50);
    heap.add(50);
    heap.add(-1000);
    heap.print_heap();
    std::cout<<heap.find_last()->value<<"\n";
    heap.del(cur);
    heap.print_heap();
    std::cout<<heap.find_last()->value<<"\n";

    std::cout<<"Heap sort\n";
    int arr[]={5,6,2,1,0,2,3,-10,2};
    int size = sizeof(arr)/sizeof(int);
    HeapArr::heapify_sort(arr, size);
    for(int i=0; i<size; i++)
        std::cout<<arr[i]<<", ";
    std::cout<<"\n";

    std::cout<<"\n\nHeapArr\n";

    HeapArr bheap;
    bheap.add(1);
    bheap.add(2);
    bheap.add(3);
    bheap.add(10);
    bheap.add(0);
    bheap.add(0);
    bheap.add(0);
    bheap.add(0);
    bheap.add(1000);
    bheap.print_heap();
    bheap.del(0);
    bheap.print_heap();

    std::cout<<"\n";
#endif

    int arr[SIZE];
    srand(time(NULL));
    for(int i=0; i<SIZE; i++){
        arr[i]=rand()%101-50;
    }
    int arr2[SIZE];
    for(int i=0; i<SIZE; i++){
        arr2[i] = arr[i];
    }
    std::vector<int>vec;
    for(int i=0; i<SIZE; i++){
        vec.push_back(arr[i]);
    }

    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff;

#ifdef POINTERS
    // Sorting on a pointer-based heap

    start = std::chrono::high_resolution_clock::now();
    HeapPtr::heapify_sort(arr, SIZE);
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;

    #ifdef PRINTING
    for(int i=0; i<SIZE; i++)
        std::cout<<arr[i]<<", ";
    std::cout<<"\n";
    #endif

    std::cout<<"Pointer-based heap: ";
    std::cout<<std::setw(9)<<diff.count()<<" s.\n";

    #endif // POINTERS

    // Sorting on an array-based heap

    start = std::chrono::high_resolution_clock::now();
    HeapArr::heapify_sort(arr2, SIZE);
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;

    #ifdef PRINTING
    for(int i=0; i<SIZE; i++)
        std::cout<<arr2[i]<<", ";
    std::cout<<"\n";
    #endif

    std::cout<<"Array-based heap: ";
    std::cout<<std::setw(9)<<diff.count()<<" s.\n";

    // STL library

    start = std::chrono::high_resolution_clock::now();
    std::make_heap(vec.begin(), vec.end());
    std::sort_heap(vec.begin(), vec.end());
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;

    #ifdef PRINTING
    for(int i=0; i<SIZE; i++)
        std::cout<<vec[i]<<", ";
    std::cout<<"\n";
    #endif // PRINTING

    std::cout<<"STL library: ";
    std::cout<<std::setw(9)<<diff.count()<<" s.\n";

    return 0;
}
