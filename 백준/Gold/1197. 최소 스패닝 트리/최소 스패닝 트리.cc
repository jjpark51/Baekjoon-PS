#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int v, e, counter;
vector<pair<int, pair<int,int>>>graph;
int parent[10001];

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

    cin >> v >> e;

    for(int i = 0; i < e; i++){
        int a,b, c;
        cin >> a >> b >> c;
        graph.push_back({c, {a,b}});
    }
    sort(graph.begin(), graph.end());

    for(int i = 1; i <= v; i++){
        parent[i] = i;
    }

    int counter = 0;

    for(int i = 0; i < graph.size(); i++){
        if(parentCheck(graph[i].second.first, graph[i].second.second) == false){
            unionParent(graph[i].second.first, graph[i].second.second);
            counter = counter + graph[i].first;
        }
    }

    cout << counter << '\n';
}