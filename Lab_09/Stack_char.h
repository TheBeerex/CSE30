#ifndef STACK_CHAR_H
#define STACK_CHAR_H

using namespace std;

#include "LinkedList_char.cpp"

class Stack : public LinkedList
{
    public:
        Stack();
        ~Stack();
        void push(char i);
        char pop();
        char& top();
};

#endif