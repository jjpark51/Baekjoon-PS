#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321

int n, e , src;
int dist[20001];
vector<pair<int,int>> graph[20001];

void solve() {
    priority_queue<pair<int,int>>pq;
    pq.push({0,src});
    dist[src] = 0;

    while(!pq.empty()){
        int cost = -pq.top().first;
        int current = pq.top().second;
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

    for(int i = 1; i <= n; i++){
        if(dist[i] == INF){
            cout << "INF" << '\n';
        }
        else {
            cout << dist[i] << '\n';
        }
    }
}

int main(){
    cin  >> n >> e >> src;
    for(int i = 0; i < e; i++){
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back({b,c});
    }
    for(int i = 1; i <= n; i++){
        dist[i] = INF;
    }

    solve();
}