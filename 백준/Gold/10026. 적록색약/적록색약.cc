#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n;
char map[101][101];
bool visited[101][101] = {false};
int calcX[4] = {0,0,1,-1};
int calcY[4] = {1,-1, 0,0};
int counter;

void solve(int a, int b) {
    queue<pair<int,int>>q; 
    q.push({a,b});

    while(!q.empty()){
        pair<int, int> cell = q.front();
        int x = cell.first;
        int y = cell.second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int adjX = x + calcX[i];
            int adjY = y + calcY[i];

            if(adjX >=0 && adjY >= 0 && adjX < n && adjY < n
                && !visited[adjX][adjY]){
                    if(map[adjX][adjY] == map[x][y]){
                        visited[adjX][adjY] = true;
                        q.push({adjX, adjY});
                    }
            }
        }
    }
}

void solveTwo(int a, int b) {
    queue<pair<int,int>>q; 
    q.push({a,b});

    while(!q.empty()){
        pair<int, int> cell = q.front();
        int x = cell.first;
        int y = cell.second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int adjX = x + calcX[i];
            int adjY = y + calcY[i];

            if(adjX >=0 && adjY >= 0 && adjX < n && adjY < n
                && !visited[adjX][adjY]){
                    char tmp = map[x][y];
                    if(tmp == 'R'){
                        if(tmp == map[adjX][adjY] || map[adjX][adjY] == 'G'){
                            visited[adjX][adjY] = true;
                            q.push({adjX, adjY});
                        }
                    }
                    else if(tmp == 'G'){
                        if(tmp == map[adjX][adjY] || map[adjX][adjY] == 'R'){
                            visited[adjX][adjY] = true;
                            q.push({adjX, adjY});
                        }
                    }
                    else{
                        if(tmp == map[adjX][adjY]){
                            visited[adjX][adjY] = true;
                            q.push({adjX, adjY});
                        }
                    }
            }
        }
    }
}
int main(){
    cin >> n;

    for(int i =0 ; i < n; i++){
        for(int j = 0; j < n; j++){
            char tmp;
            cin >> tmp;
            map[i][j] = tmp;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j]){
                solve(i,j);
                counter++;
            }
        }
    }
    // cout << "This is the normal result: " << '\n';
    cout << counter << '\n';

    memset(visited, false, sizeof(visited));
    counter = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j]){
                solveTwo(i,j);
                counter++;
            }
        }
    }
    // cout << "This is the second result: " << '\n';
    cout << counter << '\n';
}