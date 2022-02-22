#include "Stack_char.h"

using namespace std;

Stack::Stack(){}

Stack::~Stack(){}

void Stack::push(char i){
    this->insertAtFront(i);
}

char Stack::pop(){
    char temp = this->getFront();
    this->removeFromFront();
    return temp;
}

char& Stack::top(){
    char temp = this->getFront();
    char& p = temp;
    return p;
}