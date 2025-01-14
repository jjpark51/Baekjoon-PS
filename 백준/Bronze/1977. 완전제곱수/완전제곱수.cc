#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

int main() {
    int m, n;
    vector<int> result;
    
    cin >> m >> n;
    
    // Find the first perfect square >= m
    int start = ceil(sqrt(m));
    // Find the last perfect square <= n
    int end = floor(sqrt(n));
    
    // Check all perfect squares in range
    for(int i = start; i <= end; i++) {
        result.push_back(i * i);
    }
    
    int sum = 0;
    for(int num : result) {
        sum += num;
    }
    
    if(result.empty()) {
        cout << -1;
    } else {
        cout << sum << '\n';
        cout << result[0];
    }
}