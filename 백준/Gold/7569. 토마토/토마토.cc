#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n,m,k;
int map[101][101][101];
int visited[101][101][101];
int calcX[6] = {0,0,1,-1,0,0};
int calcY[6] = {1,-1, 0,0,0,0};
int calcZ[6] = {0,0,0,0,1,-1};
int minNum = 0;
queue<pair<int, pair<int, int>>>q;

void solve(int a, int b, int c){

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second.first;
        int z = q.front().second.second;
        q.pop();

        for(int i = 0; i < 6; i++){
            int adjX = x + calcX[i];
            int adjY = y + calcY[i];
            int adjZ = z + calcZ[i];

            if(adjX >= 0 && adjX < n && adjY >= 0 && adjY < m && adjZ >= 0 && adjZ < k
                 && map[adjX][adjY][adjZ] == 0){
                    q.push({adjX,{ adjY, adjZ}});
                    map[adjX][adjY][adjZ] = 1;
                    visited[adjX][adjY][adjZ] = visited[x][y][z] + 1;
                    minNum = max(minNum, visited[adjX][adjY][adjZ]);
                }
        }

    }
}

int main(){

    cin >> m >> n >> k;

    for(int r = 0; r < k; r++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> map[i][j][r];
            }
        }
    }

    for(int r = 0; r < k; r++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(map[i][j][r] == 1){
                    q.push({i,{j,r}});
                }
            }
        }
    }

    // for(int i = 0; i < q.size(); i++){
    //     cout << q.front().first << " " << q.front().second.first << " " << q.front().second.second << '\n';
    // }

    solve(q.front().first, q.front().second.first, q.front().second.second);

        for(int r= 0; r < k; r++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(map[i][j][r] == 0){
                        cout << -1;
                        return 0;
                    }
                }
            }
        }
        cout << minNum;


        // cout << "This is the result: ";

}
