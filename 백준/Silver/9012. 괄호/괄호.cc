#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isVPS(const string& temp) {
    stack<char> st;

    for (int j = 0; j < temp.size(); j++) {
        if (temp[j] == '(') {
            st.push(temp[j]);
        } else if (temp[j] == ')' && st.empty()) {
            return false;
        } else {
            st.pop();
        }
    }

    return st.empty();
}

int main() {
    int n;
    cin >> n;
    cin.ignore();  // Ignore newline after reading n

    for (int i = 0; i < n; i++) {
        string temp;
        getline(cin, temp);

        if (isVPS(temp)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}