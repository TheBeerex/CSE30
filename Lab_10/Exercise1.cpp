#include <iostream>
#include "Queue.cpp"

using namespace std;

int main(){
    Queue theQueue;

    cout << "Empty Status: " << theQueue.isEmpty() << endl;
    cout << "Size: " << theQueue.size() << endl;

    // theQueue.front();
    // theQueue.dequeue();

    theQueue.enqueue(0);
    theQueue.enqueue(1);
    theQueue.enqueue(2);
    theQueue.enqueue(3);
    theQueue.enqueue(4);
    theQueue.enqueue(5);
    theQueue.enqueue(6);
    theQueue.enqueue(7);
    theQueue.enqueue(8);
    theQueue.enqueue(9);
    
    cout << "Empty Status: " << theQueue.isEmpty() << endl;
    cout << "Size: " << theQueue.size() << endl;

    cout << "The Queue: ";
    theQueue.print();
    cout << endl;

    cout << "We popped: " << theQueue.dequeue() << endl;
    cout << "Size: " << theQueue.size() << endl;

    cout << "The Queue: ";
    theQueue.print();
    cout << endl;

    return 1;
}
