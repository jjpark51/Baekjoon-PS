#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<pair<long long, long long>> graph[10001];
bool visited[100001] = {false};
long long maxDistance;
long long y;

void dfs(long long x, long long length) {
    if(visited[x] == true){
        return;
    }
    // cout << x << " ";
    visited[x] = true;

    if(maxDistance < length){
        maxDistance = length;
        y = x;
        // cout << endl;
        // cout << "This is the current max Distance & endpoint " << endl;
        // cout << maxDistance << " & " << y << endl;
    }

    for(int i = 0; i < graph[x].size(); i++){
        dfs(graph[x][i].first, length + graph[x][i].second);
    }
}

int main(){
    int n;
    cin >> n;

    for(int i = 0 ; i < n - 1; i++){
        int a ,b , e;
        cin >> a >> b >> e;

        graph[a].push_back({b,e});
        graph[b].push_back({a,e});
    }

    dfs(1, 0);

    memset(visited, false, sizeof(visited));
    // cout << "Restart!" << endl;
    dfs(y, 0);

    cout << maxDistance;

}
