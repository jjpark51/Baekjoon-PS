#include <string>
#include <iostream>
#include <vector>
using namespace std;

int fib(int n, long long* counter) {
    *counter++;
    if(n == 1 || n == 2){
        return 1;
    }
    return fib(n-1, counter) + fib(n-2, counter);
}

int fibonacci(int n ){
    int f[41] = {0};
    f[1] = 1;
    f[2] = 1;
    int counter = 0;

    for(int i = 3; i <=n ;i++) {
        f[i] = f[i-1] + f[i-2];
        counter++;
    }
    return counter;
}

int main(){
    int n;
    cin >> n;
    long long* counter;
    cout << fib(n, counter) << endl;
    cout << fibonacci(n) << endl;
}