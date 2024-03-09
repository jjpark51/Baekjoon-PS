#include <iostream>
using namespace std;

long long gcd(long long a, long long b){
    long long c = a % b;
    if(c == 0){
        return b;
    }
    a = b;
    b = c;
    return gcd(a,b);

}
void lcm(long long a, long long b, long long c){
    cout << a * b / c << '\n';
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n ; i++){
        long long a, b;

        cin >> a >> b;

        lcm(a,b, gcd(a,b));
    }
}