#include <iostream>
#include "Queue_char.cpp"

using namespace std;

int main(){
    Queue theQueue;

    //theQueue.dequeue();

    theQueue.enqueue('D');
    
    cout << "The Queue: ";
    theQueue.print();
    cout << endl;

    theQueue.enqueue('A');
    
    cout << "The Queue: ";
    theQueue.print();
    cout << endl;
    
    cout << "We dequeued: " << theQueue.dequeue() << endl;

    cout << "Size: " << theQueue.size() << endl;

    cout << "The Queue: ";
    theQueue.print();
    cout << endl;

    theQueue.enqueue('D');

    cout << "Empty Status: " << theQueue.isEmpty() << endl;

    cout << "The Queue: ";
    theQueue.print();
    cout << endl;

    cout << "Front: " << theQueue.front() << endl;

    theQueue.enqueue('T');

    cout << "The Queue: ";
    theQueue.print();
    cout << endl;    

    return 1;
}
