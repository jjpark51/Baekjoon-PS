#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int map[51][51];
bool visited[51][51] = {false};
int calcX[8] = {0,0,-1,-1,-1,1,1,1};
int calcY[8] = {1,-1,0,1,-1,0,-1,1};

void bfs(int i, int j, vector<int>& result, int n, int m) {
    queue<pair<int,int>>q;
    q.push({i,j});
    visited[i][j] = true;
    int counter = 1;
    while(!q.empty()){
        pair<int,int> cell = q.front();
        int x = cell.first;
        int y = cell.second;
        q.pop();

        for(int i = 0; i < 8; i++){
            int adjX = x + calcX[i];
            int adjY = y + calcY[i];

            if(adjX >= 0 && adjX < n && adjY >= 0 && adjY < m && 
                visited[adjX][adjY] == false && map[adjX][adjY] == 1){
                    counter++;
                    visited[adjX][adjY] = true; 
                    q.push({adjX, adjY});
                }
        }
    }
    result.push_back(counter);
}

int main() {

    while(1){
        vector<int> result;
        int m, n;
        cin >> m >> n;
        if(m == 0 && n == 0){
            break;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> map[i][j];
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(visited[i][j] == false && map[i][j] == 1){
                    bfs(i,j, result,n,m);
                }
            }
        }
        cout << result.size() << endl;
        memset(visited, false, sizeof(visited));
        memset(map, 0, sizeof(map));
    } 
   



}