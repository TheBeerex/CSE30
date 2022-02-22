#ifndef QUEUE_H
#define QUEUE_H

using namespace std;

#include "LinkedList.cpp"

class Queue : public LinkedList
{
    public:
        Queue();
        ~Queue();
        void enqueue(int i);
        int dequeue();
        int& front();
};

#endif