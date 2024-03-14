#include <iostream>
#include <vector>
using namespace std;
int n;
int cntr;
vector<pair<int,int>> v;

void solve(int n, int start, int dest, int helper){
    if(n == 0){
        return;
    }
    cntr++;
    solve(n-1, start, helper, dest);
    v.push_back({start, dest});
    solve(n-1, helper, dest, start); 
}
int main() {
    cin >> n;

    solve(n, 1, 3,2);
    cout << cntr << '\n';
    for(int i = 0; i < v.size(); i++){
        cout << v[i].first << " " << v[i].second << '\n';
    }
}