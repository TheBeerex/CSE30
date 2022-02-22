#include "Queue.h"

using namespace std;

Queue::Queue(){}

Queue::~Queue(){}

void Queue::enqueue(int i){
    this->insertAtBack(i);
}

int Queue::dequeue(){
    if(!this->isEmpty()){
        int temp = this->getFront();
        this->removeFromFront();
        return temp;
    }else{
        cout << "Call to dequeue() generated an exception, because the queue is empty." << endl;
        throw(99);
    }
}

int& Queue::front(){
    int temp = this->getFront();
    int& p = temp;
    return p;
}