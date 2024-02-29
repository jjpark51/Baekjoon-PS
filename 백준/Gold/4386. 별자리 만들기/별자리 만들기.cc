#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;
int n, e;
vector<pair<int, pair<float, float>>>map;
vector<pair<float, pair<int, int>>>graph;
int parent[10001];

// Here we try and find the highest parent
int findParent(int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b){
    a = findParent(a);
    b = findParent(b);
    parent[b] = a;
}

bool parentCheck(int x, int y) {
    x = findParent(x);
    y = findParent(y);

    if(x == y){
        return true;
    }
    return false;
}
int main(){

    cin >> n;

    for(int i = 0; i < n; i++){
        float a,b;
        cin >> a >> b;

        map.push_back({i + 1, {a,b}});
    }

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            float x = map[i].first;
            float y = map[j].first;

            float a = map[i].second.first;
            float b = map[i].second.second;
            float c = map[j].second.first;
            float d = map[j].second.second;

            // cout << a << " " << c << "  + " << b << " " << d << '\n';
            float tmp = pow(a-c,2) + pow(b-d,2);
            // cout << tmp << '\n';
            float dist = sqrt(tmp);
            // cout << dist << '\n';
            graph.push_back({dist, {x,y}});
        }
    }
    sort(graph.begin(), graph.end());

    // for(int i = 0; i < graph.size(); i++){
    //     cout << graph[i].first << " " << graph[i].second.first << " - " << graph[i].second.second << '\n'; 
    // }
    // cout << '\n';

    // Here we initalize all of the parents to the node itself
    for(int i = 1; i <= graph.size(); i++){
        parent[i] = i;
    }

    float weight = 0;

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

    cout << fixed << setprecision(2) << weight <<  '\n';
}