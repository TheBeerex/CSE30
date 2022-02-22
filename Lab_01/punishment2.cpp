#include <iostream>
#include <string>

using namespace std;

int main(){
    int numLines;
    string lines;
    cout << "Enter the number of lines for the punishment: ";
    cin >> lines;

    try{ // Once again using try/catch with stoi for verification on both the number of lines and the typo line.
        numLines = stoi(lines);
        if(numLines < 1){
            cout << "You entered an incorrect value for the number of lines!" << endl;
            return 0;
        }
    }catch(exception e){
        cout << "You entered an incorrect value for the number of lines!" << endl;
        return 0;
    }
    
    int numTypoLine;
    string typoLine;
    cout << "Enter the line for which we want to make a typo: ";
    cin >> typoLine;

    try{
        numTypoLine = stoi(typoLine);
        if( numTypoLine < 1 || numTypoLine > numLines ){
            cout << "You entered an incorrect value for the line typo!" << endl;
            return 0;
        }
    }catch(exception e){
        cout << "You entered an incorrect value for the line typo!" << endl;
        return 0;
    }

    // for loop for the printing process, if the user input has gotten to this point, it's good to go.
    for(int i = 0; i < numLines; i++){
        if(i == numTypoLine-1){
            cout << "I will always use object oriented programing." << endl;
        }else{
            cout << "I will always use object oriented programming." << endl;
        }
    }

    return 0;
}