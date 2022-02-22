#ifndef STACK_H
#define STACK_H

using namespace std;

#include "LinkedList.cpp"

class Stack : public LinkedList
{
    public:
        Stack();
        ~Stack();
        void push(int i);
        int pop();
        int& top();
};

#endif