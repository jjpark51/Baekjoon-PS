#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;

bool visited[1001];
// long long path[100001];
vector<long long>graph[1001];

// void bfs(int n, int k) {

// }

void dfs(int x) {
    visited[x] = true;

    for(int i = 0; i < graph[x].size(); i++){
        if(!visited[graph[x][i]]){
            dfs(graph[x][i]);
        }
    }
}

int main() {
    int n, m;

    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    long long counter = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            counter++;
            dfs(i);
        }
    }

    cout << counter;
    
}