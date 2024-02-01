#include <stdio.h>
#include <stack>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>  // Include for std::fixed and std::setprecision

using namespace std;

//How to convert  a string to an int in c++?
int main(){

   string arr[4] = {""};

   for(int i = 0; i < 4; i++){
        cin >> arr[i];
   }

   long long a = stoll(arr[0] + arr[1]);
   long long b = stoll(arr[2] + arr[3]);

   cout << a + b;
}