#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector<int>a;
vector<int>b;
int main() {
    cin >> n;

    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    sort(a.begin(), a.end());


    for(int j = 0; j < n; j++){
        int tmp;
        cin >> tmp;
        b.push_back(tmp);
    }
    sort(b.begin(), b.end());

    int result = 0;

    for(int i = 0; i < n; i++){
        result += a[i] * b[n-i-1];
    }
    cout << result;

   

    

    // To make s the smallest a[i] x b[i], we need to have the smallest a values to the largest b values paired 
}