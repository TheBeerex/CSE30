#include <iostream>
#include <fstream>
#include <string>

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

int main(){
    const string fileName = "words_in.txt";
    string *arr;
    int length = countFileLines(fileName);
    arr = new string[length];
    
    fileToArr(fileName, arr, length);

    readArr(arr, length);
    
    delete[] arr;

    return 0;
}