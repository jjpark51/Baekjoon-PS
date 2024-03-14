#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int>v[100001];
int visited[100001];

void solve(int x){
    queue<int> q;
    q.push(x);
    visited[x] = 1;

    while(!q.empty()){
        int current = q.front();
        q.pop();

        for(int i = 0; i < v[current].size(); i++){
            if(visited[v[current][i]] == 0){
                visited[v[current][i]] = visited[current] + 1; 
                q.push(v[current][i]);
            }
        }
    }
}
int main() {
    int n,m, r;
    cin >> n >> m >> r;

    for(int i = 0; i < m ; i++){
        int a,b;
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    solve(r);

    for(int i = 1; i <= n; i++){
        if(visited[i] != 0){
            cout << visited[i] - 1 << '\n';
        }
        else{
            cout << -1 << '\n';
        }
    }
}