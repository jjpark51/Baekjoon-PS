#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector<int>a;
vector<pair<int,int>>b;
int new_a[52];
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
        b.push_back({-tmp, j});
    }

    vector<pair<int,int>> tmp;
    tmp = b;

    sort(tmp.begin(), tmp.end());
    // for(int i = 0; i < a.size(); i++){
    //     cout << a[i] << " ";
    // }
    // cout << '\n';

    for(int i = 0; i < tmp.size(); i++){
        // cout << tmp[i].second << ": " << -tmp[i].first << '\n';
        new_a[tmp[i].second] = a[i];
    }

    // cout << '\n';

    // for(int i = 0; i < n; i++){
    //     cout << new_a[i] << " ";
    // }
    // cout << '\n';
    int result = 0; 

    for(int i = 0; i < a.size(); i++){
        result += new_a[i] * -b[i].first;
    }
    cout << result;


    

    // To make s the smallest a[i] x b[i], we need to have the smallest a values to the largest b values paired 
}