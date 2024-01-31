#include <stdio.h>
#include <stack>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>  // Include for std::fixed and std::setprecision

using namespace std;

int main(){
    int N = 0;
    cin >> N;
    cin.ignore();

    string temp = "";
    getline(cin, temp);
    // cout << temp << endl;

    vector<int> a;
    stack<double> st;
    for(int i = 0; i < N; i++){
        int temp = 0;
        cin >> temp;
        a.push_back(temp);
    }


    for(int i = 0; i < temp.size(); i++){
        double cal = 0;
        if(isalpha(temp[i])){
            st.push(a[temp[i] - 'A']);
        }
        else {
            if(temp[i] == '*'){
                double a = st.top();
                st.pop();
                double b = st.top();
                st.pop();
                cal = b* a;
                // cout << cal << endl;
                st.push(b*a);
            }
            else if(temp[i] == '+'){
                double a = st.top();
                st.pop();
                double b = st.top();
                st.pop();
                cal = b + a;
                // cout << cal << endl;
                st.push(b+a);
            }
            else if(temp[i] == '/'){
                double a = st.top();
                st.pop();
                double b = st.top();
                st.pop();
                cal = b / a;
                // cout << cal << endl;
                st.push(b/a);
            }
            else if(temp[i] == '-'){
                double a = st.top();
                st.pop();
                double b = st.top();
                st.pop();
                cal = b - a;
                // cout << cal << endl;
                st.push(b-a);
            }
        }
    }
    cout << fixed << setprecision(2) << st.top() << endl;

}
