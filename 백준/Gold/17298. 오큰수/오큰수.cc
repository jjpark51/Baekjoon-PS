#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    stack<pair<int, int>> s;  // pair: (index, value)
    vector<int> result(N, -1);  // Initialize result vector with -1

    for (int i = 0; i < N; ++i) {
        while (!s.empty() && s.top().second < A[i]) {
            result[s.top().first] = A[i];
            s.pop();
        }
        s.push({i, A[i]});
    }

    // Output the result
    for (int i = 0; i < N; ++i) {
        cout << result[i] << " ";
    }

    return 0;
}