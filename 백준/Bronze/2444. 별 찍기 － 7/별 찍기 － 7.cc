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
        for(int j = 0; j < n - i; j++){
            cout << " ";
        }
        for(int k = 2*n - (2*i - 1); k < 2*n; k++){
            cout << "*";
        }
        cout << '\n';
    }

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 2 * (n) - i; j++){
            if(j < i - 1){
                cout << " ";
            }
            else {
             cout << "*";
            }

        }
        cout << '\n';
    }

}