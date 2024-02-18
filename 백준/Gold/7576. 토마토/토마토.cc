#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
long long map[1001][1001];
long long visited[1001][1001];
int calcX[4] = {-1,1,0,0};
int calcY[4] = {0,0,1,-1};

queue<pair<long long, long long>> q;

void bfs(){
    while(!q.empty()){
        long long x = q.front().first;
        long long y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            long long adjX = x + calcX[i];
            long long adjY = y + calcY[i];

            if(adjX >= 1 && adjX <= n && adjY >= 1 & adjY <= m 
                && visited[adjX][adjY] == -1 && map[adjX][adjY] == 0){
                    visited[adjX][adjY] = visited[x][y] + 1;
                    q.push({adjX, adjY});
                }
        }
    }
}

int main() {    
    cin >> m >> n;

    for(int i = 1; i <=n; i++){
        for(int j = 1; j <= m; j++){
            cin >> map[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            visited[i][j] = -1;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(map[i][j] == 1){
                visited[i][j] = 0;
                q.push({i,j});
            }
        }
    }
    bfs();

    long long maxDays = 0;
    int flag=  0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j<= m; j++){
            if(visited[i][j] == -1 && map[i][j] == 0){
                cout << "-1" << endl;
                flag = 1;
                break;
            }
            maxDays = max(maxDays, visited[i][j]);
        }
        if(flag == 1){
            break;
        }
    }
    if(flag != 1){
        cout << maxDays << endl;
    }

   
}