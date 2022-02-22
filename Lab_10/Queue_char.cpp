#include "Queue_char.h"

using namespace std;

Queue::Queue(){}

Queue::~Queue(){}

void Queue::enqueue(char i){
    this->insertAtBack(i);
}

char Queue::dequeue(){
    if(!this->isEmpty()){
        char temp = this->getFront();
        this->removeFromFront();
        return temp;
    }else{
        cout << "Call to dequeue() generated an exception, because the queue is empty." << endl;
        throw(99);
    }
}

char& Queue::front(){
    char temp = this->getFront();
    char& p = temp;
    return p;
}