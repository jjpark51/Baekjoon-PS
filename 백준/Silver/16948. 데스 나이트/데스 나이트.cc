#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int n;
int a,b,c,d;
int visited[201][201];
int calcX[6] = {-2,-2,0,0,2,2};
int calcY[6] = {-1,1,-2,2,-1,1};

void bfs(int a, int b, int c, int d){
    queue<pair<int,int>> q;
    q.push({a,b});

    while(!q.empty()){
        pair<int,int> cell = q.front();
        int x = cell.first;
        int y = cell.second;
        // cout << "This is the current front : "<< endl;
        // cout << x << " " << y << endl;
        q.pop();

        for(int i = 0; i < 6; i++){
            int adjX = x + calcX[i];
            int adjY = y + calcY[i];
            if(adjX >= 0 && adjX <= n && adjY >=0 && adjY <= n && 
                visited[adjX][adjY] == 0){
                    visited[adjX][adjY] = visited[x][y] + 1;
                    if(adjX == c && adjY == d){
                        cout << visited[c][d] << endl;
                        return;
                    }
                    q.push({adjX, adjY});
            }
        }
    }

    cout << "-1" << endl;
    return;
}

int main() {
    cin >> n;
    cin >> a >> b >> c >> d;

    bfs(a,b,c,d);

}