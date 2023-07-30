#include "PriorityQueueArr.h"


PriorityQueueArr::PriorityQueueArr()
{
    size = 10;
    arr = new QueueElement[size];
    start = size-1, end = size-1;
    arr[start].data = -1;
    arr[start].priority = -1;
}

PriorityQueueArr::PriorityQueueArr(int siz)
{
    size = siz;
    arr = new QueueElement[size];
    start = size-1, end = size-1;
    arr[start].data = -1;
    arr[start].priority = -1;
}

PriorityQueueArr::~PriorityQueueArr()
{
    delete [] arr;
}

void PriorityQueueArr::add(int element, int pr)
{
    if(isEmpty())
    {
        arr[start].data = element;
        arr[start].priority = pr;
        return;
    }
    int new_index = (end-1+size)%size;
    if(new_index==start) return;
    end = new_index;
    arr[end].data = element;
    arr[end].priority = pr;
    int current = end;
    int next;
    while(arr[current].priority < arr[next=(current+1)%size].priority)
    {
        std::swap(arr[current], arr[next]);
        if(next == start) break;
        current = next;
    }
}

void PriorityQueueArr::add(int element)
{
    add(element, MAX_PRIORITY);
}

int PriorityQueueArr::peek()
{
    return arr[start].data;
}

int PriorityQueueArr::pop()
{
    if(isEmpty()) return -1;
    int data;
    if(start==end)
    {
        data = arr[start].data;
        arr[start].data = -1;
        arr[start].priority = -1;
    }
    else
    {
        data = arr[start].data;
        start = (start-1+size)%size;
    }
    return data;
}

std::string PriorityQueueArr::toString()
{
    std::string result = "";
    int current = start;
    while(current!=end)
    {
        result = std::to_string(arr[current].data) + " " + result;
        current = (current-1+size)%size;
    }
    result = std::to_string(arr[end].data) + " " + result;
    return result;
}

bool PriorityQueueArr::isEmpty()
{
    return (start==end && arr[start].priority == -1 && arr[start].data == -1);
}

void PriorityQueueArr::printTab(){
    for(int i=0; i<size; i++){
        std::cout<<"E="<<arr[i].data<<" P="<<arr[i].priority<<", ";
    }
}
