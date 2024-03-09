#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {

  while(1){
    stack<char> st;
    string s;
    getline(cin, s);

    bool valid = true;


    if(s == "."){
      break;
    }

    for(int i = 0; i < s.size(); i++){
      char tmp;
      tmp = s[i];
      if(tmp == '(' || tmp == '['){
        st.push(tmp);
      }
      else if(tmp == ')' && st.empty()){
        valid = false;
        break;
      }
      else if(tmp == ']' && st.empty() ){
        // cout << "no" << '\n';
        valid = false;
        break;
      }
      else if(tmp == ')' && st.top() != '('){
        valid = false;
        // cout << "no" << '\n';
        break;
      }
      else if(tmp == ']' && st.top() != '['){
         valid = false;
        break;
      }
      else if(tmp == ')' && st.top() == '('){
        st.pop();
      }
      else if(tmp == ']' && st.top() == '['){
        st.pop();
      }
    }
    // if(!st.empty()){
    //   cout << "no" << '\n';
    // }
        while(!st.empty()){
      // cout << "no" << '\n';
      valid = false;
      st.pop();
        }
    if(valid == true){
      cout << "yes" << '\n';
    }else {
      cout << "no" << '\n';
    }

  }
}