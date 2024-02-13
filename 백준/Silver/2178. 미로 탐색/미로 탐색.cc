#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int map[101][101];
bool visited[101][101] = {false};
int dist[101][101] = {0};
int counter = 1;
int calcX[4] = {0,0,-1,1};
int calcY[4] = {1,-1,0,0};

int bfs(int i, int j, int n ,int m){
    queue<pair<int,int>>q;
    q.push({i,j});
    dist[i][j] = 1;

    while(!q.empty()){
        pair<int,int> cell = q.front();
        int x = cell.first;
        int y = cell.second;
        q.pop();

            for(int i = 0; i < 4; i++){
                int adjX = x + calcX[i];
                int adjY = y + calcY[i];
                if(adjX >= 1 && adjX <= n && adjY >= 1 && adjY <= m
                    && visited[adjX][adjY] == false && map[adjX][adjY] == 1){
                        dist[adjX][adjY] = dist[x][y] + 1;
                        q.push({adjX, adjY});
                        visited[adjX][adjY] = true;
                    }
            }
    }
    return dist[n][m];

}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%1d", &map[i][j]);
        }
    }

    cout << bfs(1,1, n , m);
    

}