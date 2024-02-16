#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
long long n, m;
long long graph[101];
long long dice[6] = {1,2,3,4,5,6};
long long visited[101];


void bfs(int x){
    queue<long long>q;
    q.push(x);
    // cout << "This is the queue sequence " << endl; 
    while(!q.empty()){
        long long current = q.front();
        q.pop();
        // cout << current << " ";
        if(current == 100){
            // cout << "We found 100 " << endl;
            // cout << "The depth is: " << visited[100] << endl;
            cout << visited[100] << endl;
            break;
        }

                for(int i = 0; i < 6; i++){
                    long long temp = current + dice[i];
                    if(visited[temp] == 0 && temp <= 100){
                        visited[temp] = visited[current] + 1;

                        if(graph[temp] != 0){
                            if(visited[graph[temp]] != 0) {
                                continue;
                            }
                            visited[graph[temp]] = visited[temp];
                            q.push(graph[temp]);
                        }
                        else {
                            q.push(temp);
                        }
                    }
                }
        }
    
}

int main(){
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        long long a, b;
        cin >> a >> b;
        graph[a] = b;
    }

    for(int i = 0; i < m ; i++){
        long long c, d;
        cin >> c >> d;
        graph[c] = d;
    }

    bfs(1);

}
