#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> v;
  for(int i = 0; i < n; i++){
    int tmp;
    cin >> tmp;

    v.push_back(tmp);


  }

    int sum = 0;
  for(int i =0; i < v.size(); i++){
    if(i != v.size() - 1){
        sum += v[i] - 1;
    }
    else{
        sum += v[i];
    }
  }

    cout << sum;

}