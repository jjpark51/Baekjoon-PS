#include <stdio.h>
#include <stack>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>  // Include for std::fixed and std::setprecision

using namespace std;

int main(){


    string word = "";

    while(getline(cin, word)){

        int lowerCount = 0;
        int upperCount = 0;
        int numCount = 0;
        int blankCount = 0;
        vector<int> result;

        for(int i = 0 ; i < word.size(); i++){
            char c = word[i];

            if(isalpha(c)){
                if(isupper(c)){
                    upperCount++;
                }
                else {
                    lowerCount++;
                }
            }
            else if(c == ' '){
                blankCount++;
            }
            else {
                numCount++;
            }
        }

        result.push_back(lowerCount);
        result.push_back(upperCount);
        result.push_back(numCount);
        result.push_back(blankCount);

        for(int i = 0; i < 4; i++){
            cout << result[i] << " ";
        }
    }


}