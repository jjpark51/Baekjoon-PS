#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int k;
    cin >> k;

    vector<long long> v(k,0);
    for(int i = 0; i < k; i++){
        cin >> v[i];
    }


    stack<long long>st;

    for(int i = 0 ; i < k; i++){
        if(v[i] != 0){
            st.push(v[i]);
        }
        else {
            st.pop();
        }
    }

    long long sum = 0;

    while(!st.empty()){
        sum += st.top();
        st.pop();
    }
    cout << sum << endl;



}



    
