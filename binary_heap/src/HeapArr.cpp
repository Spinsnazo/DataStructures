#include "HeapArr.h"


HeapArr::HeapArr()
{
    size = 10;
    elements = 0;
    heap = new int[size];
}

HeapArr::~HeapArr()
{
    delete [] heap;
}

HeapArr::HeapArr(int size)
{
    this->size = size;
    this->elements = 0;
    heap = new int[size];
}

void HeapArr::add(int element)
{
    if(elements >= size) return;
    heap[elements] = element;
    elements++;
    heapify_up(elements-1);
}

void HeapArr::heapify_up(int index)
{
    if(index < 1 || index >= elements) return;
    int parent;
    while((parent = (index%2==0) ? index/2-1 : index/2)>=0 && heap[parent]<heap[index])
    {
        std::swap(heap[index],heap[parent]);
        index = parent;
    }
}

void HeapArr::heapify_down(int index)
{
    int left_child = 0, right_child = 0;
    while(index > -1 && index<elements)
    {
        left_child = 2*index+1;
        right_child = 2*index+2;
        int maks = index;
        if(left_child<elements && heap[left_child]>heap[maks]) maks = left_child;
        if(right_child<elements && heap[right_child]>heap[maks]) maks = right_child;
        if(index==maks) break;
        std::swap(heap[index], heap[maks]);
        index = maks;
    }
}

int HeapArr::del(int index){
    int data = heap[index];
    heap[index] = heap[elements-1];
    elements--;
    int parent = 0;
    if((parent = (index%2==0) ? index/2-1 : index/2) >= 0 && heap[index]>heap[parent]) heapify_up(index);
    else heapify_down(index);
    return data;
}

void HeapArr::print_heap()
{
    for(int i=0; i<elements; i++)
    {
        std::cout<<heap[i]<<", ";
    }
    std::cout<<"\n";
}

void HeapArr::heapify_sort(int arr[], int size_arr){
    HeapArr heaap(size_arr);
    for(int i=size_arr-1; i>-1; i--){
        heaap.add(arr[i]);
    }
    for(int i=size_arr-1; i>-1; i--){
        arr[i]=heaap.heap[0];
        std::swap(heaap.heap[0], heaap.heap[heaap.elements-1]);
        heaap.del(heaap.elements-1);
        heaap.heapify_down(0);
    }
    arr[0] = heaap.heap[0];
}
