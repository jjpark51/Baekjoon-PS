#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n,m,r;
vector<long long> graph[100001];
bool visited[100001] = {false};
long long result[100001];
long long counter;
void solve(long long x){
    queue<long long>q;
    q.push(x);
    visited[x] = true;
    counter++;
    result[x] = counter;
    while(!q.empty()){
        long long current = q.front();
        q.pop();
        for(int i = 0; i < graph[current].size(); i++){
            if(!visited[graph[current][i]]){
                visited[graph[current][i]] = true;
                q.push(graph[current][i]);
                counter++;
                result[graph[current][i]] = counter;

            }
        }
    }
}

int main(){
    cin >> n >> m >> r;

    for(int i = 0; i < m; i++){
        long long a,b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 1; i <= n; i++){
        sort(graph[i].begin(), graph[i].end(), greater<long long>());
    }

    solve(r);

    for(int i = 1; i <= n; i++){
        cout << result[i] << '\n';
    }
}
