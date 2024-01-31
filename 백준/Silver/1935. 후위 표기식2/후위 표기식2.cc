#include <iostream>
#include <iomanip>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;

    string expression;
    cin >> expression;

    vector<int> operandValues(N);
    for (int i = 0; i < N; ++i) {
        cin >> operandValues[i];
    }

    stack<double> st;

    for (char ch : expression) {
        if (isalpha(ch)) {
            // Operand encountered, push corresponding value to the stack
            st.push(operandValues[ch - 'A']);
        } else {
            // Operator encountered, perform operation using the top two operands on the stack
            double operand2 = st.top();
            st.pop();
            double operand1 = st.top();
            st.pop();

            switch (ch) {
                case '+':
                    st.push(operand1 + operand2);
                    break;
                case '-':
                    st.push(operand1 - operand2);
                    break;
                case '*':
                    st.push(operand1 * operand2);
                    break;
                case '/':
                    st.push(operand1 / operand2);
                    break;
            }
        }
    }

    // Output the final result with precision up to two decimal places
    cout << fixed << setprecision(2) << st.top() << endl;

    return 0;
}
