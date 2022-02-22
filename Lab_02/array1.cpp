#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    string input;
    int length;

    cout << "Enter the size of the array:    ";
    cin >> input;
    try { // using a try to convert in case input is not an integer and throws an exception
        length = stoi(input);
        if(length < 1){
            cout << "ERROR: you entered an incorrect value for the array size";
            return 0; //ends program
        }
    } catch(const exception& e) {
        cout << "ERROR: you entered an incorrect value for the array size";
        return 0; //ends program
    }

    cout << "Enter the numbers in the array, separated by a space, and press enter:" << endl;
    getline(cin, input);
    getline(cin, input);

    int arr[length];
    int pos;
    string temp;

    try{ // using a try to convert in case input is not an integer and throws an exception
        for(int i = 0; i < length; i++){ // loop through the given line and convert it to an int array
            pos = input.find(" "); //find pos of the first space
            if(pos > 0){//if not the last integer (no more spaces exist)
                temp = input.substr(0, pos);//get s substring from the start of the input to the first space
                arr[i] = stoi(temp);//convert substring to an int and put into the array
                input.replace(0, pos+1, ""); //remove the substring
            }else{//if last integer (no more spaces exist)
                arr[i] = stoi(input);//convert rest of string into an int
            }
        }
    }catch(const exception& e){
        cout << "ERROR: non-integer input(s) for array contents";
    }

    bool increasing = true;

    cout << "{  ";
    for(int i = 0; i < length-1; i++){ // loop through the array to see if it is increasing
        cout << arr[i] << "  ";
        if(arr[i] > arr[i+1]){
            increasing = false;
        }
    }
    cout << arr[length-1] << "  }" << endl;

    if(increasing){
        cout << "This IS an increasing array!";
    }else{
        cout << "This is NOT an increasing array!";
    }
}


