#include <iostream>
#include <string>

using namespace std;

int main(){
    string input;
    int sideLength;
    cout << "Enter the size of a 2D array:    ";
    cin >> input;
    sideLength = stoi(input);
    if(sideLength < 1 || sideLength > 10){
        cout << "invalid range: must be an int from 1-10";
        return 0; //end program
    }

    int arr[sideLength][sideLength];

    int pos;
    string temp;
    getline(cin, input);
    for(int i = 0; i < sideLength; i++){
        cout << "Enter row " << i+1 << " of integers for the 2d array, separated by a space, and press enter: " << endl;
        getline(cin, input);

        for(int j = 0; j < sideLength; j++){
            pos = input.find(" ");
            if(pos > 0){
                temp = input.substr(0, pos);
                arr[j][i] = stoi(temp);
                input.replace(0, pos+1, ""); 
            }else{
                arr[j][i] = stoi(input);
            }
        }
        
    }

    int negCounter = 0;
    for(int j = 0; j < sideLength; j++){
        for(int i = 0; i < sideLength; i++){
            if(arr[j][i] < 0){
            negCounter++;
            }
        }
    }

    if(negCounter > 0){
        cout << "There are " << negCounter << " negative integers!";
    }else{
        cout << "All integers are non-negative!";
    }
}
