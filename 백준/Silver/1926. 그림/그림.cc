#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
int map[501][501];
bool visited[501][501] = {false};
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int n, m;
int area;

void bfs(int a, int b){
    queue<pair<int,int>>q;
    q.push({a,b});
    visited[a][b] = true;

    while(!q.empty()){
        pair<int,int> cell = q.front();
        int x = cell.first;
        int y = cell.second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int adjX = x + dx[i];
            int adjY = y + dy[i];
            if(adjX > 0 && adjX <= n && adjY > 0 && adjY <= m 
                && !visited[adjX][adjY] && map[adjX][adjY] == 1){
                    area++;
                    q.push({adjX,adjY});
                    visited[adjX][adjY] = true;
                }
        }
    }
}
int main() {
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> map[i][j];
        }
    }

    int counter = 0;
    int maxArea = 0;
    for(int i =1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(!visited[i][j] && map[i][j] == 1){
                area = 1;
                bfs(i,j);
                counter++;
                maxArea = max(maxArea, area);
            }
        }
    }
    cout << counter << '\n';
    cout << maxArea << '\n';
}