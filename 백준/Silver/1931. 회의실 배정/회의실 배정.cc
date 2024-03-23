#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector<pair<long long, long long>>v;
int main() {
    cin >> n;

    for(int i = 0; i < n; i++){
        long long a,b;
        cin >> a >> b;
        v.push_back({b,a});
    }
    sort(v.begin(), v.end());

    // for(int i = 0; i < n; i++){
    //     cout << v[i].first << " - " << v[i].second << '\n';
    // }
    int cnt = 1;
    int tmp = v[0].first;
    for(int i = 1;  i < v.size();i++){
        if(tmp > v[i].second){
            continue;
        }
        tmp = v[i].first;
        cnt++;
    }
    cout << cnt << '\n';


}