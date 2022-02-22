#include <iostream>
#include <string>

using namespace std;

struct Time{
    int hour, minute, second;
};

bool getTimeFromUser(Time& t, bool startEnd){
    string input;
    if(startEnd){
        cout << "Enter an end time (HH:MM:SS): " << endl;
    }else{
        cout << "Enter a start time (HH:MM:SS): " << endl;
    }
    getline(cin, input);
    if(input.find(":", 0) == 2 && input.find(":", 3) == 5){
        int temp1 = stoi(input.substr(0, 2));
        int temp2 = stoi(input.substr(3, 2));
        int temp3 = stoi(input.substr(6, 2));
        if(temp1 >= 0 && temp1 < 24 && temp2 >= 0 && temp2 < 60 && temp3 >= 0 && temp3 < 60){
            t.hour = temp1;
            t.minute = temp2;
            t.second = temp3;
        }else{
            cout << "Invalid time entered" << endl;
            return 0;
        }
    }else{
        cout << "Invalid time entered" << endl;
        return 0;
    }
    return 1;
}

void print24Hour(Time& t){
    if(t.hour < 10){
        cout << "0";
    }
    cout << t.hour << ":";
    if(t.minute < 10){
        cout << "0";
    }
    cout<< t.minute << ":";
    if(t.second < 10){
        cout << "0";
    }
    cout << t.second;
}

int main(){
    Time startTime;
    Time endTime;
    if(getTimeFromUser(startTime, 0)){
        if(getTimeFromUser(endTime, 1)){
            cout << "You began at ";
            print24Hour(startTime); 
            cout << " and ended at ";
            print24Hour(endTime);
            cout << endl;
        }
    }
    return 0;
}