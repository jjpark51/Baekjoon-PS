#include <stdio.h>
#include <queue>
#include <iostream>

using namespace std;
int main() {
    queue<int> q;

    int n = 0;
    cin >> n;
    cin.ignore();

    for(int i = 0; i < n; i++){
        string temp = "";
        cin >> temp;

        if(temp == "push"){
            int k = 0;
            cin >> k;
            q.push(k);
        }
        else if(temp == "pop"){
            if(q.empty()){
                cout << "-1" << endl;
            }
            else {
                cout << q.front() << endl;
                q.pop();
            }
        }
        else if(temp == "size"){
            cout << q.size() << endl;
        }
        else if(temp == "empty"){
            if(q.empty()){
                cout << "1" << endl;
            }
            else {
                cout << "0" << endl;
            }
        }
        else if(temp == "front") {
            if(q.empty()){
                cout << "-1" << endl;
            }
            else {
                cout << q.front() << endl;
            }
        }
        else if(temp == "back") {
            if(q.empty()){
                cout << "-1" << endl;
            }
            else {
                cout << q.back() << endl;
            }
        }
        
    }
}