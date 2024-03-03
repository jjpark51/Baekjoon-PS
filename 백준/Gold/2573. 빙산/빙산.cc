#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
int map[301][301];
int tmp[301][301];
bool visited[301][301] = {false};
int n, m;
int year = 1;
int calcX[4] = {0,0,1,-1};
int calcY[4] = {1,-1,0,0};

void bfs(int a, int b){

    visited[a][b] = true;

    int iceberg = 0;
    

        
        for(int i = 0; i < 4; i++){
            int adjX = a + calcX[i];
            int adjY = b + calcY[i];

            if(adjX > 0 && adjY > 0 && adjX <= n && adjY <= m   
                && map[adjX][adjY] == 0){
                    iceberg++;
                    // cout << "We increment the iceberg at " << x << " " << y << '\n';
            }
        }
        // visited[x][y] = true;
        // if(iceberg > 0){
        //     cout << x << " and " << y << " are reduced from " << map[x][y] << " to " << map[x][y] - iceberg << '\n';
        //     }
            tmp[a][b] = map[a][b] - iceberg;
            
            if(tmp[a][b] < 0){
                tmp[a][b] = 0;
            }
        
}

void icebergCount(int a, int b){
    queue<pair<int,int>>q;
    q.push({a,b});
    visited[a][b] = true;

    while(!q.empty()){
        pair<int,int> cell = q.front();
        int x = cell.first;
        int y = cell.second;
        q.pop();

        for(int i = 0 ; i < 4; i++){
            int adjX = x + calcX[i];
            int adjY = y + calcY[i];

            if(adjX > 0 && adjY > 0 && adjX <= n && adjY <= m
                && !visited[adjX][adjY]){
                    if(map[adjX][adjY] != 0){
                        q.push({adjX, adjY});
                        visited[adjX][adjY] = true;
                    }
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

    while(1){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(map[i][j] != 0){
                    bfs(i,j);
                }
            }
        }

        // // This is the result after 1 year
        // cout << "This is the result after 1 year : " <<'\n';
        // for(int i = 1; i <= n; i++){
        //     for(int j = 1; j <= m; j++){
        //         cout << tmp[i][j] << " ";
        //     }
        //     cout << '\n';
        // }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                map[i][j] = tmp[i][j];
            }
        }
        memset(visited, false, sizeof(visited));

        // Here we will do our island count
        int counter = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(!visited[i][j] && map[i][j] != 0){
                    // cout << "We are inspecting from " << i << " " << j << '\n';
                    icebergCount(i,j);
                    counter++;
                }
            }
        }
        // cout << "counter: " << counter << '\n';
        memset(visited, false, sizeof(visited));


        if(counter > 1){
            cout << year;
            return 0;
        }
        // cout << "We increment the year " << year << '\n';
        year++;
        // Here we check if all of the icebergs melted, if yes then we return 0
        int zeroCounter=  0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(map[i][j] == 0){
                    zeroCounter++;
                }
            }
        }
        if(zeroCounter == n * m){
            cout << 0;
            return 0;
        }

    }
}