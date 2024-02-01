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
    int result[26] = {-1};

    for(int i = 0 ; i< 26; i++){
        result[i] = -1;
    }

    for(int i = 0; i < word.size(); i++){
        int checker = word[i] - 'a';
        if(result[checker] == -1){
            result[checker] = i;
        }
    }

    for(int i = 0 ; i < 26; i++){
        cout << result[i] << " ";
    }

}