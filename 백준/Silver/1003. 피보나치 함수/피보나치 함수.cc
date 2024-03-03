#include <iostream>
using namespace std;
long long zeroCount;
long long oneCount;

int fibonacci(int n) {
    if (n == 0) {
        zeroCount++;
        // printf("0");
        return 0;
    } else if (n == 1) {
        oneCount++;
        // printf("1");
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        int n;
        cin >> n;

        long long zero[41];
        zero[0] = 1;
        zero[1] = 0;
        long long one[41];
        one[0] = 0;
        one[1] = 1;
        for(int i = 2; i <= n; i++){
            zero[i] = zero[i - 1] + zero[i-2];
            one[i] = one[i - 1] + one[i- 2];
        }
        cout << zero[n] << ' ' << one[n] << '\n';
        // fibonacci(n);
        // cout << zeroCount << ' ' << oneCount << '\n';
        // zeroCount = 0;
        // oneCount = 0;
    }

}