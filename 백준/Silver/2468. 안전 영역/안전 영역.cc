#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
int n;
int map[101][101];
int tmp[101][101];
bool visited[101][101] = {false};
int calcX[4] = {0,0,1,-1};
int calcY[4] = {1,-1,0,0};
int maxNum;        
int maxCounter = 0;

void bfs(int a, int b) {
    queue<pair<int,int>>q;
    q.push({a,b});
    visited[a][b] = true;

    while(!q.empty()){
        pair<int, int> cell = q.front();
        int x = cell.first;
        int y = cell.second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int adjX = x + calcX[i];
            int adjY = y + calcY[i];

            if(!visited[adjX][adjY] && adjX >= 0 && adjY >= 0 && adjX < n && adjX < n && tmp[adjX][adjY] != 0){
                q.push({adjX,adjY});
                visited[adjX][adjY] = true;
            }
        }
    }
    
}
int main() {
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0;  j < n; j++){
            cin >> map[i][j];
            maxNum = max(maxNum, map[i][j]);
        }
    }


    for(int height = 1; height <= maxNum; height++){
        int counter = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(map[i][j] < height){
                    tmp[i][j] = 0;
                }
                else{
                    tmp[i][j] = map[i][j];
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j] && tmp[i][j] != 0){
                    bfs(i,j);
                    counter++;
                }
            }
        }
        // cout << "height: " << height << '\n';
        // cout << "counter: " << counter << '\n';
        maxCounter = max(maxCounter, counter);
        memset(visited, false, sizeof(visited));
        memset(tmp, 0, sizeof(tmp));
        
    }
    cout << maxCounter - 1;


}