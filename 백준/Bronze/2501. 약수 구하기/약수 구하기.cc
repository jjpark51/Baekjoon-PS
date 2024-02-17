#include <iostream>
using namespace std;

int n, k;
void solve(int n, int k){
    int counter = 0;

    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            counter++;
            if(counter == k){
                cout << i << endl;
                return;
            }
        }
        
    }
    cout << 0;
}

int main() {

    cin >> n >> k;
    solve(n,k);
   
}