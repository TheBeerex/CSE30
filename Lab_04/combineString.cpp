#include <string>
#include <iostream>

using namespace std;

string combineStr(string str, int count){
    string temp = "";
    if(count < 0){
        return "Count less than 0";
    }
    for(int i = 0; i < count; i++){
        temp += str;
    }
    return temp;
}


int main(){
    string strInput;
    int intInput;

    cout << "Enter a string: ";
    cin >> strInput;
    cout << "Enter an integer: ";
    cin >> intInput;

    string output = combineStr(strInput, intInput);
    cout << output;

    return 0;
}