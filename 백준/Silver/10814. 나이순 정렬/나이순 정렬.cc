#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<pair<pair<int, int>, string>>v;

    int n;

    cin >> n;

    for(int i = 0; i < n ; i++){
        int tmp;
        cin >> tmp;
        cin.ignore();
        string s;
        cin >> s;

        v.push_back({{tmp, i}, s});
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++){

        cout << v[i].first.first << " " << v[i].second << '\n';
        
    }
}