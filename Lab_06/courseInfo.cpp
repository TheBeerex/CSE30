#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Time{
    int hour, minute, second;

    Time(){}
    Time(int h, int m, int s){
        this->hour = h;
        this->minute = m;
        this->second = s;
    }
    Time(string t){
        if(verifyTimeString(t)){
            this->hour = stoi(t.substr(0, 2));
            this->minute = stoi(t.substr(3, 2));
            this->second = stoi(t.substr(6, 2));
        }
    }
    bool verifyTimeString(string t){
        if(t.find(":", 0) == 2 && t.find(":", 3) == 5){
            int temp1 = stoi(t.substr(0, 2));
            int temp2 = stoi(t.substr(3, 2));
            int temp3 = stoi(t.substr(6, 2));
            if(temp1 >= 0 && temp1 < 24 && temp2 >= 0 && temp2 < 60 && temp3 >= 0 && temp3 < 60){
                return 1;
            }else{
                cout << "Invalid time entered" << endl;
                return 0;
            }
        }else{
            cout << "Invalid time entered" << endl;
            return 0;
        }
    }
    void coutTime(){
        if(this->hour < 10){
            cout << "0";
        }
        cout << this->hour << ":";
        if(this->minute < 10){
            cout << "0";
        }
        cout<< this->minute << ":";
        if(this->second < 10){
            cout << "0";
        }
        cout << this->second;
    }
};

struct Course{
    string name;
    int credits;
    bool majorReq;
    double avgGrade;
    string days;
    Time startTime, endTime;
};

bool hasNCourses(string fName, int n){
    int counter = 0;
    ifstream file;
    file.open(fName);
    string data;
    if(n < 1){
        return 0;
    }
    while(!file.eof()){
        file >> data;
        counter++;
    }
    file.close();
    if(counter >= n*7 + 1){
        return 1;
    }else{
        return 0;
    }
}

void printCourse(Course c, int i){
    cout << "COURSE " << i << ": " << c.name << endl;
    if(c.majorReq){
        cout << "note: this course is a major req." << endl;
    }
    cout << "Number of Credits: " << c.credits << endl;
    cout << "Days of Lecture: " << c.days << endl;
    cout << "Lecture Times: "; c.startTime.coutTime(); cout << " to "; c.endTime.coutTime(); cout << endl;
    cout << "Stat: on average, students get " << c.avgGrade << "% in this class" << endl;
}

int main(){
    string const fileName = "in.txt";
    ifstream file;
    int courseCount;
    Course courseHolder;
    string data;
    file.open(fileName);
    getline(file, data);
    courseCount = stoi(data);
    if(hasNCourses(fileName, courseCount)){
        for(int i = 0; i < courseCount; i++){
            getline(file, data);
            courseHolder.name = data;
            getline(file, data);
            courseHolder.credits = stoi(data);
            getline(file, data);
            if(data == "1"){
                courseHolder.majorReq = 1;
            }else{
                courseHolder.majorReq = 0;
            }
            getline(file, data);
            courseHolder.avgGrade = stod(data);
            getline(file, data);
            courseHolder.days = data;
            getline(file, data);
            courseHolder.startTime = Time(data);
            getline(file, data);
            courseHolder.endTime = Time(data);
            printCourse(courseHolder, i+1);
        }
        file.close();
    }
    
    return 0;
}