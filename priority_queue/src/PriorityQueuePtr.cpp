#include "PriorityQueuePtr.h"


PriorityQueuePtr::PriorityQueuePtr()
{
    sentinel = new QueueNode;
    sentinel->data = -1;
    sentinel->priority = -1;
    sentinel->next = sentinel;
    sentinel->previous = sentinel;
}

PriorityQueuePtr::~PriorityQueuePtr()
{
    QueueNode *current = sentinel;
    while(current!=sentinel)
    {
        QueueNode* nxt = current->next;
        delete current;
        current = nxt;
    }
}

bool PriorityQueuePtr::isEmpty()
{
    return (sentinel->next==sentinel/*&&sentinel->previous==sentinel*/);
}

void PriorityQueuePtr::add(int element, int pr)
{
    QueueNode* neww = new QueueNode;
    neww->data = element;
    neww->priority = pr;
    neww->next = sentinel;
    neww->previous = sentinel->previous;
    sentinel->previous = neww;
    neww->previous->next = neww;

    QueueNode *current = neww;
    while(current->previous != sentinel && current->previous->priority > current->priority){
        std::swap(current->data, current->previous->data);
        std::swap(current->priority, current->previous->priority);
        current = current->previous;
    }

}

void PriorityQueuePtr::add(int element){
    add(element, MAX_PRIORITY);
}

int PriorityQueuePtr::pop(){
    if(isEmpty()) return -1;
    int data = sentinel->next->data;
    QueueNode* removed = sentinel->next;
    sentinel->next = sentinel->next->next;
    sentinel->next->previous = sentinel;
    delete removed;
    return data;
}

int PriorityQueuePtr::peek(){
    if(isEmpty()) return -1;
    return sentinel->next->data;
}

std::string PriorityQueuePtr::toString(){
    std::string result = "";
    QueueNode* current = sentinel->previous;
    while(current!=sentinel){
        result += std::to_string(current->data) + " ";
        current = current->previous;
    }
    return result;
}
