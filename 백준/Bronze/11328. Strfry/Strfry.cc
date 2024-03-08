#include <iostream>
#include <cstring>
using namespace std;
int freqA[26];
int freqB[26];
int main() {
  cin.tie(0);
  int n;
  cin >> n;

  for(int i = 0; i < n; i++){
    string a,b;
    cin >> a >> b;

    for(int i = 0; i <a.size(); i++){
      freqA[a[i] - 'a']++;
    }
    for(int j = 0; j < b.size(); j++){
      freqB[b[j] - 'a']++;
    }
    bool flag  = true;
    for(int i = 0; i < 26; i++){
      if(freqA[i] != freqB[i]){
        cout << "Impossible"<<'\n';
        flag = false;
        break;
      }
    }
    if(flag == true){
      cout << "Possible" << '\n';
    }

  memset(freqA, 0, sizeof(freqA));
  memset(freqB, 0, sizeof(freqB));
  }
}