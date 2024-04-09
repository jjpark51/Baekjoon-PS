#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int arr[27];

int main() {

string s;
cin >> s;

    for(int i = 0; i < s.size(); i++){
        char c = s[i];
        char tmp = tolower(c);

        arr[tmp - 'a']++;
    }

    int maxNum = 0;
    int index = 0;
    for(int i = 0; i < 26; i++){
        if(maxNum < arr[i]){
            maxNum = arr[i];
            index = i;
        }
    }

    for(int i = 0; i < 26; i++){
        if(i != index && arr[index] == arr[i]){
            cout << "?" << '\n';
            return 0;
        }
    }

    char result = toupper('a' + index);
    cout << result << '\n';

}