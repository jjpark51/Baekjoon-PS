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

    for(int i = 0; i < word.size(); i++){
        char c = word[i];
        
        if(isalpha(c)){
            if(isupper(c)){
                int index = c - 'A';
                if(index < 13){
                    word[i] = c + 13;
                } else {
                    word[i] = 'A' + index- 13;
                }
            }
            else {
                int index = c - 'a';
                if(index < 13){
                    word[i] = c + 13;
                } else {
                    word[i] = 'a' + index- 13;
                }
            }
        }
    }

    for(int i = 0 ; i < word.size(); i++){
        cout << word[i];
    }
}