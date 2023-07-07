#ifndef PriorityQueueArr_H
#define PriorityQueueArr_H

#include <iostream>

#define MAX_PRIORITY 1000


struct QueueElement{
    int data;
    int priority;
};

/*
    A class to store a priority queue in a regular array.
    A circular buffer is used to follow up the changes that are done to
    the data structure.
*/

class PriorityQueueArr
{
    public:
        PriorityQueueArr();
        PriorityQueueArr(int siz);
        ~PriorityQueueArr();
        void add(int element, int pr); // With priority
        void add(int element);         // Priority = MAX_PRIORITY
        int peek();                    // Returns the first element in the queue
        int pop();
        bool isEmpty();
        std::string toString();
        void printTab();
    private:
        QueueElement *tab;
        int size;
        int start;
        int end;
};

#endif // PriorityQueueArr_H
