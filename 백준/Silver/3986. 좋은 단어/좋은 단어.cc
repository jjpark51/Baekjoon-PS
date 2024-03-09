#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
  long long n;

  cin >> n;
  cin.ignore();
int cnt = 0;
  // cout << "This is our n: " << n << '\n';
  for(int i = 0; i < n; i++){
    string s;
    getline(cin, s);
    stack<char> st;

    for(int j = 0; j < s.size(); j++){
      char tmp;
      tmp = s[j];

      if(st.empty()){
        st.push(tmp);
      }
      else {
        if(tmp == st.top()){
          st.pop();
        }
        else{
          st.push(tmp);
        }
      }

  }

  if(st.empty()){
    cnt++;
  }

}
  cout << cnt;

}