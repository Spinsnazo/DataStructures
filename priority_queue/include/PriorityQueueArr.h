#ifndef PriorityQueueArr_H
#define PriorityQueueArr_H

#include <iostream>

#define MAX_PRIORITY 1000

// A struct to store a queue element
struct QueueElement{
    int data;
    int priority;
};

/**
 * A class to store a priority queue in a regular array.
 * A circular buffer is used to follow up the changes that are done to
 * the data structure.
*/

class PriorityQueueArr
{
    public:
        PriorityQueueArr();
        PriorityQueueArr(int siz);
        ~PriorityQueueArr();
        // With priority
        void add(int element, int pr);
        // Priority = MAX_PRIORITY
        void add(int element);
        // Returns the first element in the queue without removing it
        int peek();
        int pop();
        bool isEmpty();
        std::string toString();
        void printTab();
    private:
        QueueElement *arr;
        int size;
        int start;
        int end;
};

#endif // PriorityQueueArr_H
