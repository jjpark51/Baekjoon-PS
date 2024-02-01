#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <math.h>


using namespace std;

int main(){
    string word = "";
    getline(cin, word);
    long long n;
    cin >> n;

    cout << word[n -1] << endl;


}