#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = 1; i < n; i++){
        for(int k = 2*n - i; k < 2*n; k++){
            cout << "*";
        }
        for(int j = 0; j < n - i; j++){
            // cout << " ";
        }

        cout << '\n';
    }

    for(int i = n; i >= 1; i--){
        for(int j = 0; j < n; j++){
            if(j < (2*i - i)){
                cout << "*";
            }
            else {
            //  cout << " ";
            }

        }
        cout << '\n';
    }

}