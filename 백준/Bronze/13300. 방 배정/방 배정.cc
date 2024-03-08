#include <iostream>
#include <vector>
using namespace std;
int arr[1001][1001];

int main(){
  int n, k;
  cin >> n >> k;

  for(int i = 0; i < n; i++){
    int sex, grade;
    cin >> sex >> grade;
    if(sex == 0){
      arr[grade][0]++;
    }
    else{
      arr[grade][1]++;
    }
  }

  int cnt=0;
  for(int i = 1; i<= 6; i++){
    for(int j = 0; j < 2; j++){
      if(arr[i][j] % 2 == 0){
        cnt = cnt + (arr[i][j] / 2);
      }
      else{
        cnt = cnt + (arr[i][j] / 2) + 1;
      }
    }
  }
  cout << cnt;

}