#include <iostream>
#include <stack>

using namespace std;
int n;
int main() {

  cin >> n;
  stack<int> st;
  int cnt = 0;
  long long answer = 0;

  for(int i = 0; i < n; i++){
    int tmp;
    cin >> tmp;
    while(!st.empty()){
      if(st.top() > tmp){
        break;
      }
      st.pop();

    }
    answer += st.size();
    st.push(tmp);
  }

  cout << answer << '\n';
}