#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    if(a % b == 0){
        return b;
    }
    return gcd(b, a%b);
}

long long lcm(long long a, long long b){
    return (a * b) / gcd(a,b);
}

int main() {
    long long a,b;

    cin >> a >> b;

    cout << lcm(a,b) << endl;

}