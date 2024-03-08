#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define INT_MAX 987654321;
int n;
int map[101][101];
int visited[101][101];
int depth[101][101];
bool sea[101][101] = {false};
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void bfs(int a, int b, int cnt){
  queue<pair<int,int>>q;
  q.push({a,b});
  visited[a][b] = cnt;

  while(!q.empty()){
    pair<int,int> cell = q.front();
    int x = cell.first;
    int y = cell.second;
    q.pop();
    
    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx >= 0 && nx < n && ny >= 0 && ny < n && visited[nx][ny] == 0 && map[nx][ny] == 1){
        visited[nx][ny] = cnt;
        q.push({nx,ny});
      }
    }
  }
}


int solve(int a, int b, int cnt){
  queue<pair<int,int>>q;
  q.push({a,b});
  sea[a][b] = true;
// here we initialize the sea matrix

  while(!q.empty()){
    pair<int,int> cell = q.front();
    int x = cell.first;
    int y = cell.second;
  
    q.pop();

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx >= 0 && nx < n && ny >= 0 && ny < n && sea[nx][ny] == false ){
        if( map[nx][ny] == 1 && visited[nx][ny] != cnt){
          // cout << "Land Ho! We have found another island!  " << '\n';
          // cout << depth[x][y] << '\n';
          depth[nx][ny] = depth[x][y];
          // cout << "We are returning distance " << depth[nx][ny] << '\n';
          return depth[nx][ny];
        }
        else if(map[nx][ny] == 0){
          q.push({nx,ny});
          depth[nx][ny] = depth[x][y] + 1;
          sea[nx][ny] = true;
        }  
        
      }
    }
  } 
  // cout << "We couldn't find any other island...";
  return INT_MAX; 
}
int main() {
  cin >> n;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      int tmp;
      cin >> tmp;
      map[i][j] = tmp;
    }
  }

  int cnt = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(visited[i][j] == 0 && map[i][j] == 1)
        {
          cnt++;
           bfs(i,j, cnt);
        }      
    }
  }
//   cout << "This is the visited matrix : " << '\n';
// for(int i = 0; i < n; i++){
//   for(int j = 0; j < n; j++){
//     cout << visited[i][j] << ' ';
//   }
//   cout << '\n';
// }

  // cout << "We have a total of " << cnt << " islands" << '\n';
  int minNum = INT_MAX;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(map[i][j] == 1){
        minNum = min(minNum, solve(i,j, visited[i][j]));
        // cout << "shortest distance is: " << minNum << '\n';
        memset(sea, false, sizeof(sea));
        memset(depth, 0, sizeof(depth));
      }
    }
  }
  // cout << "Answer: " << '\n';
  cout << minNum << '\n';
}