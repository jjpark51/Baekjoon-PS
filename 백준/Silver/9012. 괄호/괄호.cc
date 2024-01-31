#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isVPS(const string& str) {
    stack<char> s;

    for (char ch : str) {
        if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            if (s.empty()) {
                return false;  // Unmatched closing parenthesis
            } else {
                s.pop();
            }
        }
    }

    return s.empty();  // Stack should be empty for a valid VPS
}

int main() {
    int T;
    cin >> T;
    cin.ignore();  // Ignore newline after reading T

    for (int i = 0; i < T; ++i) {
        string input;
        getline(cin, input);

        if (isVPS(input)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}