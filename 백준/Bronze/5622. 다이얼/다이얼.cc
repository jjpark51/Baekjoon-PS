#include <string>
#include <iostream>

using namespace std;

int main(){
    string s;
    getline(cin, s);

    int counter = 0;
    for(int i = 0 ; i < s.size(); i++) {
        if(s[i] >= 'A' && s[i] <= 'C'){
            counter += 3;
        }
        else if(s[i] >= 'D' && s[i] <= 'F'){
            counter += 4;
        }
        else if(s[i] >= 'G' && s[i] <= 'I'){
            counter += 5;
        }
        else if(s[i] >= 'J' && s[i] <= 'L'){
            counter += 6;
        }
        else if(s[i] >= 'M' && s[i] <= 'O'){
            counter += 7;
        }
        else if(s[i] >= 'P' && s[i] <= 'S'){
            counter += 8;
        }
        else if(s[i] >= 'T' && s[i] <= 'V'){
            counter += 9;
        }
        else if(s[i] >= 'W' && s[i] <= 'Z'){
            counter += 10;
        }
    }

    cout << counter << endl;;
}