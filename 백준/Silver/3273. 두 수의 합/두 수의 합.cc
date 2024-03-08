#include <iostream>
#include <vector>
using namespace std;
int n;
int freq[1000002];
int main() {
  cin >> n;
  
  for(int i = 0; i < n; i++){
    int tmp;
    cin >> tmp;
    freq[tmp]++;
  }

  int x;
  cin >> x;
  int counter = 0;
  for(int i = 1; i< x; i++){
      if(i <= 1000000 && x - i <= 1000000 && freq[i] == 1 && freq[x - i] == 1 && i != x - i){
      counter++;
      // cout << "( " << i << ", " << x- i <<" )" << '\n';
      freq[i] = 0;
      freq[x-i] = 0;
    }
    
  }
  cout << counter;

}