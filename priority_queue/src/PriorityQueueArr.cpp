#include "PriorityQueueArr.h"


PriorityQueueArr::PriorityQueueArr()
{
    size = 10;
    tab = new QueueElement[size];
    start = size-1, end = size-1;
    tab[start].data = -1;
    tab[start].priority = -1;
}

PriorityQueueArr::PriorityQueueArr(int siz)
{
    size = siz;
    tab = new QueueElement[size];
    start = size-1, end = size-1;
    tab[start].data = -1;
    tab[start].priority = -1;
}

PriorityQueueArr::~PriorityQueueArr()
{
    delete [] tab;
}

void PriorityQueueArr::add(int element, int pr)
{
    if(isEmpty())
    {
        tab[start].data = element;
        tab[start].priority = pr;
        return;
    }
    int new_index = (end-1+size)%size;
    if(new_index==start) return;
    end = new_index;
    tab[end].data = element;
    tab[end].priority = pr;
    int current = end;
    int next;
    while(tab[current].priority < tab[next=(current+1)%size].priority)
    {
        std::swap(tab[current], tab[next]);
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
    return tab[start].data;
}

int PriorityQueueArr::pop()
{
    if(isEmpty()) return -1;
    int data;
    if(start==end)
    {
        data = tab[start].data;
        tab[start].data = -1;
        tab[start].priority = -1;
    }
    else
    {
        data = tab[start].data;
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
        result = std::to_string(tab[current].data) + " " + result;
        current = (current-1+size)%size;
    }
    result = std::to_string(tab[end].data) + " " + result;
    return result;
}

bool PriorityQueueArr::isEmpty()
{
    return (start==end && tab[start].priority == -1 && tab[start].data == -1);
}

void PriorityQueueArr::printTab(){
    for(int i=0; i<size; i++){
        std::cout<<"E="<<tab[i].data<<" P="<<tab[i].priority<<", ";
    }
}
