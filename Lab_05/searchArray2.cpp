#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int countFileLines(string fName){
    int counter = 0;
    ifstream file;
    file.open(fName);
    string data;
    while(!file.eof()){
        file >> data;
        counter++;
    }
    file.close();
    return counter;
}

void fileToArr(string fName, string arr[], int length){
    ifstream file;
    file.open(fName);
    string data;

    for(int i = 0; i < length; i++){
        getline(file, data);
        arr[i] = data;
    }

    file.close();
}

void readArr(string arr[], int length){
    for(int i = 0; i < length; i++){
        cout << arr[i] << endl;
    }
}

int checkArraySort(string arr[], int length){
    int direction = -99;
    if (length > 1){
        if(arr[0] < arr[1]){
            direction = 1;
            for(int i = 1; i < length-1; i++){
                if(arr[i] > arr[i+1]){
                    direction = 0;
                    break;
                }
            }
        }else if(arr[0] > arr[1]){
            direction = -1;
            for(int i = 1; i < length-1; i++){
                if(arr[i] < arr[i+1]){
                    direction = 0;
                    break;
                }
            }
        }
    }else{
        direction = 0;
    }

    return direction;
}

int binarySearchL(string arr[], int length, string key){
    int start = 0;
    int end = length-1;
    int mid;

    while(end >= start){
        mid = start + floor((end - start)/2);
        if(arr[mid] == key){
            return mid;
        }else if(arr[mid] > key){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }
    return -1;
}

int main(){
    const string fileName = "words_in.txt";
    string *arr;
    int length = countFileLines(fileName);
    arr = new string[length];
    
    fileToArr(fileName, arr, length);

    readArr(arr, length);

    int check = checkArraySort(arr, length);

    if(check == 1){
        cout << "The array is sorted in ascending order." << endl;
    }else{
        cout << "The array is not sorted in ascending order, exiting program." << endl;

        delete[] arr;
        return 0;
    }

    //search
    string key;
    cout << "What string are we searching for? ";
    cin >> key;

    int foundIndex;
    foundIndex = binarySearchL(arr, length, key);
    
    if(foundIndex >= 0){
        cout << "Key " << key << " was found at index " << foundIndex << endl;
    }else{
        cout << "Key " << key << " was not found in the array" << endl;
    }

    delete[] arr;
    return 0;
}
