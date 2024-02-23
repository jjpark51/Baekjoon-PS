#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n,m,k;
int map[51][51];
bool visited[51][51] = {false};
int calcX[4] = {0,0,1,-1};
int calcY[4] = {1,-1, 0,0};

void solve(int a, int b){
    queue<pair<int,int>>q;
    q.push({a,b});
    visited[a][b] = true;

    while(!q.empty()){
        pair<int,int> cell = q.front();
        int x = cell.first;
        int y = cell.second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int adjX = x + calcX[i];
            int adjY = y + calcY[i];

            if(adjX >= 0 && adjX <= n && adjY >= 0 && adjY <= m
                && !visited[adjX][adjY] && map[adjX][adjY] == 1){
                    q.push({adjX, adjY});
                    visited[adjX][adjY] = true;
                }
        }

    }
}

int main(){

    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        int counter = 0;

        cin >> m >> n >> k;

        for(int i = 0; i < k; i++){
            int a,b;
            cin >> a >> b;

            map[b][a] = 1;
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && map[i][j] == 1){
                    solve(i,j);
                    counter++;
                }
            }
        }
        memset(visited, false, sizeof(visited));
        memset(map, 0, sizeof(map));
        // cout << "This is the result: ";
        cout << counter << '\n';
    }

}
