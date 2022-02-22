#ifndef QUEUE_H
#define QUEUE_H

using namespace std;

#include "LinkedList_char.cpp"

class Queue : public LinkedList
{
    public:
        Queue();
        ~Queue();
        void enqueue(char i);
        char dequeue();
        char& front();
};

#endif