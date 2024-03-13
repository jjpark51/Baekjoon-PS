#include <iostream>
#include <queue>
using namespace std;

int map[1001][1001];
bool visited[1001][1001] = {false};
int n,m,k;
int dx[2] = {0,1};
int dy[2] = {1,0};
int counter = 1;;

int main() {
    cin >> n >> m >> k;

    if((n-1) + (m-1) < k){
        cout << "YES" << '\n';
        for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            // map[i][j] = counter;
            cout << counter << " ";
            counter++;
        }
        cout <<'\n';
        counter = i + 2;
    }

    }
    else {
        cout << "NO" << '\n';
    }
    

    // queue<pair<int,int>>q;
    // q.push({1,1});
    // map[1][1] = 1;
    // visited[1][1] = true;

    // while(!q.empty()){
    //     pair<int,int> cell = q.front();
    //     int x = cell.first;
    //     int y = cell.second;
    //     // cout << "x: " << x <<" y: " << y << '\n';
    //     int qSize = q.size();
    //     q.pop();
        
    //     for(int i = 0; i < qSize; i++){
    //         for(int i = 0; i < 2;i++){
    //             int nx = x + dx[i];
    //             int ny = y + dy[i];
    //             // cout << "nx: " << nx << '\n';
    //             // cout << "ny: " << ny << '\n';

    //             if(nx > 0 && nx <= n && ny > 0 && ny <= m && !visited[nx][ny]){
    //                 visited[nx][ny] = true;
    //                 q.push({nx,ny});
    //                 // cout << nx << " , " << ny << '\n';
    //                 map[nx][ny] = map[x][y] + 1;
    //                 // cout << "value: " << map[nx][ny] << '\n';
    //             }
    //         }
    //     }

    // }

    // if(map[n][m] <= k && visited[n][m] == true){
    //     cout << "YES" << '\n';
    //     for(int i = 1; i <= n; i++){
    //         for(int j = 1; j <= m; j++){
    //            cout << map[i][j] << " ";
    //         }
    //         cout << '\n';
    //     }
    // }
    // else {
    //     cout << "NO" << '\n';
    // }


}