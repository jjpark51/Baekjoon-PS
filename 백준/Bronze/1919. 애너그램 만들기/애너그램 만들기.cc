#include <iostream>
#include <string>
using namespace std;
int freqA[26];
int freqB[26];

int main() {
  string a,b;
  cin >> a >> b;

  for(int i = 0; i < a.size(); i++){
    freqA[a[i] - 'a']++;
  }
  for(int i = 0; i < b.size(); i++){
    freqB[b[i] - 'a']++;
  }

  int cnt = 0;
  for(int i = 0; i < 26; i++){
    if(freqA[i] > freqB[i]){
      while(1){
        freqA[i]--;
        cnt++;
        if(freqA[i] == freqB[i]){
          break;
        }
      }
    }
    else if(freqB[i] > freqA[i]){
      while(1){
        freqB[i]--;
        cnt++;
        if(freqA[i] == freqB[i]){
          break;
        }
      }
    }
  }
  cout << cnt;

}