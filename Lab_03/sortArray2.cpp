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

    //Check if it is already sorted
    bool decreasing = true;
    for(int i = 0; i < length-1; i++){
        if(arr[i] < arr[i+1]){
            decreasing = false;
        }
    }
    if(decreasing){
        cout << "The array is already sorted in descending order." << endl; //and don't bother sorting
    }else{
        // SELECTION SORT (largest to the front)
        int i, j, minIndex;
        int swaps;
        for(i = 0; i < length-1; i++){
            minIndex = i;
            for(j = i + 1; j < length; j++){
                if(arr[j] > arr[minIndex]){
                    minIndex = j;
                }
            }
            int temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
            swaps ++;
        }
    }

    cout << "The sorted array in descending order is: {  ";
    for(int i = 0; i < length; i++){
        cout << arr[i] << "  ";
    }
    cout << "}" << endl << "The algorithm selected the maximum for the traverse of the array.";

}