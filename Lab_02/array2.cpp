#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
    string input;
    cout << "Enter the string to reverse: " << endl;
    
    getline(cin, input);

    char temp1;
    char temp2;
    for(int i = 0; i < (input.size()/2); i++){ //loop through the array swapping the chars and the beginning chars and ending chars
        temp1 = input[i];
        temp2 = input[(input.size()-1)-i];
        input[(input.size()-1)-i] = temp1; 
        input[i] = temp2;
    }
    cout << "The reverse of the string is: " << endl << input;
    
    return 0;
}