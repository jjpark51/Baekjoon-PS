#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;

vector<pair<int,string>> v;
int main() {
    cin >> n;

    for(int i = 0; i < n ; i++){
        string s;
        cin >> s;
        v.push_back({s.size(), s});
    }
    sort(v.begin(), v.end());
    cout << v[0].second << '\n';
    for(int i = 1; i < n; i++){

        if(i > 0 && v[i].second != v[i-1].second){
            cout << v[i].second << '\n'; 
        }
    }

}