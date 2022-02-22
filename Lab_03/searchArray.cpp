#include <iostream>
#include <string>

using namespace std;

int main(){
    string input;
    int length;

    cout << "Enter the size of the array:    ";
    cin >> input;
    try {
        length = stoi(input);
        if(length < 1){
            cout << "ERROR: you entered an incorrect value for the array size!";
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

    try{ 
        for(int i = 0; i < length; i++){ 
            pos = input.find(" "); 
            if(pos > 0){
                temp = input.substr(0, pos);
                arr[i] = stoi(temp);
                input.replace(0, pos+1, "");
            }else{
                arr[i] = stoi(input);
            }
        }
    }catch(const exception& e){
        cout << "ERROR: non-integer input(s) for array contents";
        return 0; //ends program
    }

    // LINEAR SEARCH ALGORITHM
    cout << "Enter a number to search for in the array";
    cin >> input;
    int ops = 0;
    int found = -1;
    int key;
    try{
        key = stoi(input);
        for(int i = 0; i < length; i++){
            ops ++;
            if(arr[i] == key){
                found = i;
                break;
            }
        }
    } catch(const exception& e){
        cout << "ERROR: invalid key";
        return 0; //ends program
    }
    if(found < 0){
        cout << "Key, " << key << ", was not found. ";
    } else{
        cout << "Key, " << key << ", was found at index " << found << ", taking " << ops << " checks. ";
    }

    if(ops == 1){
        cout << "This was a best case.";
    }else if(ops == length){
        cout << "This was a worst case.";
    }
}