#include <iostream>
#include "Stack_char.cpp"

using namespace std;


int main()
{
    Stack theStack;

    cout << "Empty Status: " << theStack.isEmpty() << endl;

    theStack.push('A');
    
    cout << "The Stack: ";
    theStack.print();
    cout << endl;

    theStack.push('Y');
    
    cout << "The Stack: ";
    theStack.print();
    cout << endl;

    cout << "Size: " << theStack.size() << endl;

    cout << "We popped: " << theStack.pop() << endl;
    cout << "Empty Status: " << theStack.isEmpty() << endl;

    cout << "The Stack: ";
    theStack.print();
    cout << endl;

    theStack.push('D');

    cout << "The Stack: ";
    theStack.print();
    cout << endl;

    cout << "Top: " << theStack.top() << endl;

    theStack.push('T');

    cout << "The Stack: ";
    theStack.print();
    cout << endl;    

    theStack.pop();

    cout << "The Stack: ";
    theStack.print();
    cout << endl;

    return 1;
}
