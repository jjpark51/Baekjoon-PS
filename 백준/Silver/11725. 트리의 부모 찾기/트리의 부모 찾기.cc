#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long long n;
vector<long long> graph[100001];
long long visited[100001];

void solve(int a){
    queue<int>q;
    q.push(a);

    while(!q.empty()){
        int current = q.front();
        q.pop();
        for(int i = 0; i < graph[current].size(); i++){
            if(visited[graph[current][i]] == 0){
                visited[graph[current][i]] = current;
                q.push(graph[current][i]); 
            }
        }
    }
}
int main(){
    cin >> n;

    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    solve(1);

    for(int i = 2; i <= n; i++){
        cout << visited[i] << '\n';
    }

}