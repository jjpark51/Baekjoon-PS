#include <iostream>
#include <string>
using namespace std;

string s;
int freq[10];

int main() {

  cin >> s;

  for(int i = 0; i < s.size(); i++){
    char c  = s[i];
    // cout << c << '\n';
    if(c == '9' && (freq[9] > freq[6]) ){
      // cout << "first" << '\n';
      freq[6]++;
    }
    else if(c == '6' && (freq[6] > freq[9]) ){
      // cout << "second" << '\n';
      freq[9]++;
    }
    else{
      // cout << "last" <<'\n';
      freq[c - '0']++;
    }
  }

  int maxNum = 0;
  int maxIndex = -1;
  for(int i = 0; i < 10; i++){
    if(maxNum < freq[i]){
        maxNum = freq[i];
        maxIndex = i;
    }
  }
  // cout << maxIndex << '\n';
  cout << maxNum;

}