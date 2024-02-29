#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstring>
using namespace std;
long long n, e;
long long parent[200001];
long long total;

// Here we try and find the highest parent
long long findParent(long long x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = findParent(parent[x]);
}

void unionParent(long long a, long long b){
    a = findParent(a);
    b = findParent(b);
    parent[b] = a;
}

bool parentCheck(long long x, long long y) {
    x = findParent(x);
    y = findParent(y);

    if(x == y){
        return true;
    }
    return false;
}
int main(){

while(1){

    vector<pair<long long, pair<long long, long long>>>graph;

    cin >> n >> e;
    if(n == 0 && e == 0){
        break;
    }

    for(int i = 0; i < e; i++){
        long long a,b,c ;
        cin >> a >> b >> c;

        graph.push_back({c, {a,b}});
    }

    for(int i = 0; i < e; i++){
        total += graph[i].first;
    }

    sort(graph.begin(), graph.end());

    // for(int i = 0; i < graph.size(); i++){
    //     cout << graph[i].first << " " << graph[i].second.first << " - " << graph[i].second.second << '\n'; 
    // }
    // cout << '\n';

    // Here we initalize all of the parents to the node itself
    for(long long i = 1; i <= n; i++){
        parent[i] = i;
    }

    long long weight = 0;

    // 1. We go through all of the graph edges
    for(int i = 0; i < graph.size(); i++){
        // 2. We check if the nodes are connected 
        if(parentCheck(graph[i].second.first, graph[i].second.second) == false){
            // 3. If the nodes are not connected, we connect the nodes using Union function
            unionParent(graph[i].second.first, graph[i].second.second);
            // 4. We add the weight 
            weight = weight + graph[i].first;
        }
    }

    cout << total - weight <<  '\n';
    total = 0;
    memset(parent, 0, sizeof(parent));
}
}