#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <stack>

// How to extract individual words in strings in C++?
using namespace std;
int main() { 
    stack<char> st;
    int n = 0;

    // To store an input line in a single variable -> getline(cin, temp)
    cin >> n;
    cin.ignore();

    for(int i = 0; i < n; i++){
        string temp;
        getline(cin, temp);
        
        istringstream iss(temp);
        string word; 
        string backward;

        while(iss >> word) {
            for(int i = 0 ; i < word.size(); i++){
                st.push(word[i]);
            }
            while(!st.empty()){
                cout << st.top();
                st.pop();
            }
            cout << " ";
        }
        cout << endl;
    }

}