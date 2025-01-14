#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = 0;

    for(int i = n; i >= 1; i-- ){
        sum += i;
    }

    cout << sum;
}