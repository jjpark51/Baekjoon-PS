#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321

int n, e , x, y;
int dist[20001];
vector<pair<int,int>> graph[20001];

void solve() {
    // We use pq to optimize
    // priority queue uses the distance for max/min heap
    // We use priority queue to efficiently select the vertex with the smallest distance among vertices not yet processed

    priority_queue<pair<int,int>>pq;
    pq.push({0,1});
    dist[1] = 0;

    while(!pq.empty()){
        int cost = -pq.top().first; // turning negative cost to positive
        int current = pq.top().second; // current node value
        pq.pop();

        for(int i = 0; i < graph[current].size(); i++){
            int next = graph[current][i].first;
            int nextCost = graph[current][i].second;

            if(dist[next] > cost + nextCost){
                dist[next] = cost + nextCost;
                pq.push({-dist[next], next});
            }
        }
    }

    // for(int i = 1; i <= n; i++){
    //     if(dist[i] == INF){
    //         cout << "INF" << '\n';
    //     }
    //     else {
    //         cout << dist[i] << '\n';
    //     }
    // }
    if(dist[n] == INF){
        cout << -1;
    }
    else {
        cout << dist[n] << '\n';
    }
}

int main(){
    cin  >> n >> e;
    for(int i = 0; i < e; i++){
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }

    cin >> x >> y;
    // This is how we initialize the distance array
    for(int i = 1; i <= n; i++){
        dist[i] = INF;
    }

    solve();
}
