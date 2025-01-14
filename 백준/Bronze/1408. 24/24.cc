#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

int main() {

    string input;
    string target;

    cin >> input;
    cin >> target;

    string hour = input.substr(0,2);
    string minute = input.substr(3,2);
    string seconds = input.substr(6,2);

    string targetHour = target.substr(0,2);
    string targetMinute = target.substr(3,2);
    string targetSeconds = target.substr(6,2);

    int a = stoi(hour);
    int b = stoi(minute);
    int c = stoi(seconds);

    int d = stoi(targetHour);
    int e = stoi(targetMinute);
    int f = stoi(targetSeconds);

    int resultA = c + 60*b + 3600*a;
    int resultB = f + 60*e + 3600*d;

    int difference = resultB - resultA;

    if(difference < 0) {
        difference += 24 * 3600;
    }

    int finalHour = (difference / 3600);
    int finalMin = ((difference % 3600) / 60);
    int finalSec = (difference % 60);

    if(finalHour < 10){
        cout << "0" << finalHour << ":";
    }
    else {
        cout << finalHour << ":";
    }

    if(finalMin < 10){
        cout << "0" << finalMin << ":";
    }
    else {
        cout << finalMin << ":";
    }

    if(finalSec < 10) {
        if(finalSec != 0){
            cout << "0" << finalSec;

        }
        else{
            cout << "00";
        }
    }
    else {
        cout << finalSec;
    }
}