#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> graph[10001];
bool visited[10002];
bool visitB[10002];

void bfs(int v) {
    queue<int>q;
    q.push(v);

    while(!q.empty()){
        int x = q.front();
        q.pop();
        visited[x] = true;
        cout << x << ' ';
        for(int i = 0; i < graph[x].size(); i++){
            if(!visited[graph[x][i]]){
                q.push(graph[x][i]);
                visited[graph[x][i]] = true;
            }
        }

    }

}

void dfs(int x) {
    visitB[x] = true;
    cout << x << ' ';

    for(int i = 0; i < graph[x].size(); i++){
        if(!visitB[graph[x][i]]){
            dfs(graph[x][i]);
        }
    }
}


int main() {
    int n, m, v;
    cin >> n >> m >> v;

    int a, b;

    vector<bool> visit(n+1, false);

    for(int i = 1; i <= m; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);

    }

    for(int i = 1; i <= n; i++){
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(v);
    cout << endl;
    bfs(v);

}