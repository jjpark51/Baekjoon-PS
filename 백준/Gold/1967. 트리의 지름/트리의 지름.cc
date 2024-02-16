#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<pair<long long, long long>> tree[10001];
long long dist = 0;
bool visited[10001] = {false};
long long y = 0;

void dfs(long long x, long long length) {
    if(visited[x] == true){
        return;
    }
    visited[x] = true;

    if(dist < length) {
        dist = length;
        y = x;
    }

    for(int i = 0;  i< tree[x].size(); i++){
        dfs(tree[x][i].first, length + tree[x][i].second);
    }
}

int main() {
    long long n;
    cin >> n;

    for(int i = 0; i < n -1; i++){
        int a , b, c;
        cin >> a >> b >> c;

        tree[a].push_back({b,c});
        tree[b].push_back({a,c});
    }

    dfs(1,0);

    dist = 0;
    memset(visited, false, sizeof(visited));

    dfs(y, 0);
    cout << dist;

}
