#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, m;
int a, b;
vector<int>graph[101];
int visited[101];

int bfs(int src, int target) {
    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int current = q.front();
        q.pop();

        for(int i = 0 ; i < graph[current].size(); i++){
            if(visited[graph[current][i]] == 0){
                q.push(graph[current][i]);
                visited[graph[current][i]] = visited[current] + 1;

                if(graph[current][i] == target){
                    return visited[graph[current][i]];
                }
            }
        }
    }
    // cout << "We can not find the target" << '\n';
    return 0;
}

int main() {
    cin >> n;
    cin >> a >> b;
    cin >> m;

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int result = bfs(a, b);

    if(result == 0){
        // cout << "Not in the same connected graph" << '\n';
        cout << -1;
    }
    else {
        cout << result;
    }

}