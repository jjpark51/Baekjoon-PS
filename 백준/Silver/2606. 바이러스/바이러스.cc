#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k;
vector<int>graph[101];
bool visited[101] = {false};

void bfs(int a) {
    queue<int> q;
    q.push(a);
    visited[a] = true;
    int counter = 0;

    while(!q.empty()){
        int x = q.front();
        q.pop();
        // cout << x << " is the current front value" << endl;

        for(int i = 0; i < graph[x].size(); i++){
            if(!visited[graph[x][i]]){
                q.push(graph[x][i]);
                visited[graph[x][i]] = true;
                counter++;
            }
        }
    }
    cout << counter;

}

int main() {
    cin >> n;
    cin >> k;

    for(int i = 0; i < k; i++){
        int x,y;
        cin >> x >> y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    bfs(1);
}