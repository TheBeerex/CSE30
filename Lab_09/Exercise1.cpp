#include <iostream>
#include "Stack.cpp"

using namespace std;


int main()
{
    Stack theStack;

    cout << "Empty Status: " << theStack.isEmpty() << endl;
    cout << "Size: " << theStack.size() << endl;

    theStack.push(0);
    theStack.push(1);
    theStack.push(2);
    theStack.push(3);
    theStack.push(4);
    theStack.push(5);
    theStack.push(6);
    theStack.push(7);
    theStack.push(8);
    theStack.push(9);
    
    cout << "Empty Status: " << theStack.isEmpty() << endl;
    cout << "Size: " << theStack.size() << endl;

    cout << "The Stack: ";
    theStack.print();
    cout << endl;

    cout << "We popped: " << theStack.pop() << endl;
    cout << "Size: " << theStack.size() << endl;

    cout << "The Stack: ";
    theStack.print();
    cout << endl;

    return 1;
}
