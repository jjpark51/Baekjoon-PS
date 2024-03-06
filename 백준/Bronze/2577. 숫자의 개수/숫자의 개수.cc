#include <iostream>
#include <string>
using namespace std;

int a,b,c;
int freq[10];
int main() {

  cin >> a >> b >> c;

  int result = a * b * c;

  string s = to_string(result);

  for(int i = 0; i < 10; i++){
    char c = s[i];
    freq[c - '0']++;
  }
  for(int i = 0; i < 10; i++){
    cout << freq[i] << '\n';
  }

}