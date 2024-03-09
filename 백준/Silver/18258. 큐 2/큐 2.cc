#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
  queue<int> q;
  int n;
  cin >> n;

  for(int i = 0; i < n; i++){
    string tmp;
    cin >> tmp;
    if(tmp == "push"){
      int k;
      cin >> k;
      q.push(k);
      // cout << k << '\n';
    }
    else if(tmp == "front"){
      if(!q.empty()){
       cout << q.front() << '\n';
      }
      else{
        cout << -1 << '\n';
      }
    }
    else if(tmp == "back"){
      if(!q.empty()){
        cout << q.back() << '\n';
      }
      else{
        cout << -1 << '\n';
      }
    }
    else if(tmp == "pop"){
      if(!q.empty()){
        cout << q.front() << '\n';
        q.pop();
      }
      else {
        cout << -1 << '\n';
      }
    }
    else if(tmp == "size"){
      cout << q.size() << '\n';
    }
    else if(tmp == "empty"){
      if(!q.empty()){
        cout << 0 << '\n';

      }
      else{
        cout << 1 << '\n';
      }
    }


  }
}