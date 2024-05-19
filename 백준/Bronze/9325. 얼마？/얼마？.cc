#include <iostream>
#include <vector>

using namespace std;

int main() {

    

    int t;
    int result = 0;
    cin >> t;

    for(int i = 0; i < t; i++){
        int base = 0;

        cin >> base;

        int k = 0;
        cin >> k;

        int p,q;

        for(int i = 0; i < k; i++){
            cin >> p >> q;
            base += p * q;
        }

        cout << base << '\n';
    }




}