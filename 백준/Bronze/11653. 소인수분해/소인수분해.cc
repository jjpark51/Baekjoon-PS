#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int i = 2;
    while(1){

        if(n % i == 0){
            cout << i << '\n';
            n = n / i;
        }
        else {
            i++;
            if(n < i){
                break;
            }
        }
    }
}