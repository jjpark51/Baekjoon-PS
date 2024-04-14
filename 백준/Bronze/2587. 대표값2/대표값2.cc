#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;



int main() {
  int a;
  vector<int> v;
  for(int i = 0; i < 5; i++){
    int a;
    cin >> a;
    v.push_back(a);
  }

    int sum = 0;
  for(int i = 0; i < 5; i++){
    sum += v[i];
  }
  cout << sum / 5 << '\n';

  sort(v.begin(), v.end());

  cout << v[2] << '\n';



}