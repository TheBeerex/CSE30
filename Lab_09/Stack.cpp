#include "Stack.h"

using namespace std;

Stack::Stack(){}

Stack::~Stack(){}

void Stack::push(int i){
    this->insertAtFront(i);
}

int Stack::pop(){
    int temp = this->getFront();
    this->removeFromFront();
    return temp;
}

int& Stack::top(){
    int temp = this->getFront();
    int& p = temp;
    return p;
}