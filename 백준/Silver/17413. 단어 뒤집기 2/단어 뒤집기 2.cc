#include <stdio.h>
#include <stack>
#include <string>
#include <iostream>

using namespace std;
void printStack(stack<char>& st) {
    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
}
int main() {
    string temp = "";
    char c;
    stack<char> st;
    getline(cin, temp);

    for(int i = 0; i < temp.size(); i++){
        c = temp[i];
        
        if(c == '<'){
            printStack(st);

            while(1){
                cout << temp[i];
                i++;
                if(temp[i] == '>'){
                    cout << temp[i];
                    break;
                }
            }
        }
        else if(c == ' '){
            printStack(st);
            cout << " ";
        }
        else {
            st.push(c);
        }
    }

    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
    

}