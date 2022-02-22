#include "Time.cpp"
#include <string>
#include <iostream>

using namespace std;

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
            t.setHour(temp1);
            t.setMinute(temp2);
            t.setSecond(temp3);
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
    if(t.getHour() < 10){
        cout << "0";
    }
    cout << t.getHour() << ":";
    if(t.getMinute() < 10){
        cout << "0";
    }
    cout<< t.getMinute() << ":";
    if(t.getSecond() < 10){
        cout << "0";
    }
    cout << t.getSecond();
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