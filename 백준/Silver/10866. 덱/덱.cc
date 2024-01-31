#include <stdio.h>
#include <queue>
#include <iostream>

using namespace std;
int main() {
    deque<int> dq;

    int N = 0;

    cin >> N;

    for(int i = 0 ; i < N; i++){
        string temp = "";

        cin >> temp;

        if(temp == "push_back"){
            int k = 0; 
            cin >> k;
            dq.push_back(k);
        }
        
        else if(temp == "push_front"){
            int k = 0; 
            cin >> k;
            dq.push_front(k);
        }
        else if(temp == "pop_front"){
            if(dq.empty()){
                cout << "-1" << endl;
            }
            else {
                cout << dq.front() << endl;
                dq.pop_front();
            }
        }
        else if(temp == "pop_back"){
            if(dq.empty()){
                cout << "-1" << endl;
            }
            else {
                cout << dq.back() << endl;
                dq.pop_back();
            }        }
        else if(temp == "size"){
            cout << dq.size() << endl;
        }
        else if(temp == "empty"){
            if(dq.empty()){
                cout << "1" << endl;
            }
            else {
                cout << "0" << endl;
            }
        }
        else if(temp == "front"){
            if(dq.empty()){
                cout << "-1" << endl;
            }
            else {
                cout << dq.front() << endl;
            }
        }
        else if(temp == "back"){
            if(dq.empty()){
                cout << "-1" << endl;
            }
            else {
                cout << dq.back() << endl;
            }
        }
    }
}