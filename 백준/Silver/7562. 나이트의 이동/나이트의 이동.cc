#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int t;
int map[301][301];
int dist[301][301];
bool visited[301][301];
int calcX[8] = {-2,-2,-1,-1,1,1,2,2};
int calcY[8] = {-1,1,-2,2,2,-2,1,-1};

int bfs(int n, int startX, int startY, int targetX, int targetY) {
    queue<pair<int,int>>q;
    q.push({startX, startY});
    dist[startX][startY] = 0;
    visited[startX][startY] = true;

    while(!q.empty()){
        pair<int,int> cell = q.front();
        int x = cell.first;
        int y = cell.second;
        q.pop();

        for(int i = 0; i < 8; i++){
            int adjX = x + calcX[i];
            int adjY = y + calcY[i];
            if(adjX >= 0 && adjX < n && adjY >= 0 && adjY < n 
                && visited[adjX][adjY] == false){
                    dist[adjX][adjY] = dist[x][y] + 1;
                    q.push({adjX, adjY});
                    visited[adjX][adjY] = true;
                }
        }
    }

    return dist[targetX][targetY];
}

int main(){
    cin >> t;

    for(int i = 0; i < t; i++){
        // cout << "This is a new test case: " << endl;
        int n;
        cin >> n;
        
        int startX, startY;
        cin >> startX >> startY;

        int targetX, targetY;
        cin >> targetX >> targetY;

        // cout << "These will be going into bfs: " << endl;
        // cout << n << " " << startX << " " << startY <<" " << targetX << " " << targetY << endl;
        // cout << endl << "Result : ";
        cout << bfs(n, startX, startY, targetX, targetY) << endl;;

        memset(map, 0 , sizeof(map));
        memset(visited, false, sizeof(visited));
        memset(dist, 0 , sizeof(dist));
        
    }

}