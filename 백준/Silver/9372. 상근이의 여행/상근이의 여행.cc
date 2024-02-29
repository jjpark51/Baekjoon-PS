#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int t;
int n,m;
vector<int> graph[1001];
bool visited[1001] = {false};
int counter;

void bfs(int a){
    queue<int> q;
    q.push(a);

    while(!q.empty()){
        int current = q.front();
        q.pop();

        for(int i = 0; i < graph[current].size(); i++){
            if(!visited[graph[current][i]]){
                q.push(graph[current][i]);
                counter++;
                visited[graph[current][i]] = true;
            }
        }

    }
}

int main(){
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n >> m;

        for(int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        bfs(1);
        cout << counter -1 << '\n';
        memset(visited, 0, sizeof(visited));
        memset(graph, 0, sizeof(graph));
        counter = 0;
    }

}