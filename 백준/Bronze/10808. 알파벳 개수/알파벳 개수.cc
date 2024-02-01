#include <stdio.h>
#include <stack>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>  // Include for std::fixed and std::setprecision

using namespace std;

int main(){
  string word = "";
  getline(cin, word);

  int result[26] = {0};

  for(int i = 0; i < word.size(); i++){
    int counter = 0;
    counter = word[i] - 'a';
    result[counter]++;
  }
  for(int i = 0 ; i < 26; i++){
    cout << result[i] << " ";
  }



}