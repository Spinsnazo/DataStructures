#ifndef PriorityQueuePtr_H
#define PriorityQueuePtr_H

#include <iostream>

#define MAX_PRIORITY 1000

// A struct to store a queue node
struct QueueNode{
    int data;
    int priority;
    QueueNode* next;
    QueueNode* previous;
};

/**
 * A class to store a priority queue using a doubly linked list.
*/

class PriorityQueuePtr
{
    public:
        PriorityQueuePtr();
        ~PriorityQueuePtr();
        void add(int element, int pr);
        void add(int element);
        int pop();
        int peek();
        bool isEmpty();
        std::string toString();
    private:
        QueueNode *sentinel;
};

#endif // PriorityQueuePtr_H
