#include <iostream>
#include <vector>

using namespace std;
int n;

int main() {
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n- i - 1; j++){
            cout << " ";
        }
        for(int j = 0; j < i + i + 1; j++){
            cout <<"*";
        }
        cout << "\n";
    }
   

}