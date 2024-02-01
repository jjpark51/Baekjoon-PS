#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    int c;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;

        vector<int> numbers(n);
        for (int j = 0; j < n; ++j) {
            cin >> numbers[j];
        }

        long long sum = 0;  // Use long long to avoid overflow for large inputs

        for (int j = 0; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                sum += gcd(numbers[j], numbers[k]);
            }
        }

        cout << sum << endl;
    }

    return 0;
}