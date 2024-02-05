#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    long long maxSum = -1001;
    long long currentSum = 0;

    for (int i = 1; i <= n; i++) {
        currentSum = max(v[i], currentSum + v[i]);
        maxSum = max(maxSum, currentSum);
    }

    cout << maxSum << endl;

    return 0;
}