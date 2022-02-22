#include <iostream>
#include <string>

using namespace std;

int main(){
    string input;
    cout << "Enter the number of lines for the punishment: ";
    cin >> input;

    try{ // Using a try/catch since stoi throws an exception if it can't convert a string to int. Also adds additional layer of verification
        if( stoi(input) > 0 ){
            for (int i = 0; i < stoi(input); i++){
                cout << "I will always use object oriented programming." << endl;
            }
        }else{
            cout << "You entered an incorrect value for the number of lines!" << endl;
        }
    }catch(exception e){
        cout << "You entered an incorrect value for the number of lines!" << endl;
    }
}