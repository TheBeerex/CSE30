#include <string>
#include <iostream>

using namespace std;

void sortArray(bool upDown, int (&a)[], int size){
    if(upDown){ //Ascending
        //Check if it is already sorted
        bool increasing = true;
        for(int i = 0; i < size-1; i++){
            if(a[i] > a[i+1]){
                increasing = false;
            }
        }
        if(increasing){
            // Don't bother sorting
        }else{
            // SELECTION SORT (lowest to the front)
            int i, j, minIndex;
            for(i = 0; i < size-1; i++){
                minIndex = i;
                for(j = i + 1; j < size; j++){
                    if(a[j] < a[minIndex]){
                        minIndex = j;
                    }
                }
                int temp = a[minIndex];
                a[minIndex] = a[i];
                a[i] = temp;
            }
        }
    }else{ //Descending
        bool decreasing = true;
        for(int i = 0; i < size-1; i++){
            if(a[i] < a[i+1]){
                decreasing = false;
            }
        }
        if(decreasing){
            // Dont bother sorting
        }else{
            // SELECTION SORT (largest to the front)
            int i, j, minIndex;
            for(i = 0; i < size-1; i++){
                minIndex = i;
                for(j = i + 1; j < size; j++){
                    if(a[j] > a[minIndex]){
                        minIndex = j;
                    }
                }
                int temp = a[minIndex];
                a[minIndex] = a[i];
                a[i] = temp;
            }
        }
    }
}

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

    bool upDown;
    cout << "Would you like the array sorted ascending or descending? (a/d): ";
    cin >> input;
    if(input == "a"){
        upDown = 1;
    }else{
        upDown = 0;
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

    //Print array
    for(int i = 0; i < length; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    //Call sortArray
    sortArray(upDown, arr, length);

    for(int i = 0; i < length; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

}