#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int m,n,k;
int map[101][101]; // map[y][x];
int dx[4] = { 0,0,1,-1};
int dy[4] = {1,-1,0,0};
queue<pair<int,int>>q;
vector<int> area;
bool visited[101][101] = {false};

void solve(int a, int b) {
  // cout << "we are inside bfs function " << '\n';
  queue<pair<int,int>> qq;
  qq.push({b,a});
  int tmp = 1;
  visited[b][a] = true;

  while(!qq.empty()){
    // cout << "going through bfs" << '\n';
    pair<int,int> cell = qq.front();
    int y = cell.first;
    int x = cell.second;
    qq.pop();

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[ny][nx]){
        visited[ny][nx] = true;
        qq.push({ny, nx});
        tmp++;
      }
    }
  }
  area.push_back(tmp);
}

int main() {
  cin >> m >> n >> k;

  for(int i = 0; i < k; i++){
    int a,b,c, d;
    cin >> a >> b >> c >> d;
    q.push({b,a});
    q.push({d,c});
  }

  // We initialize all of the squares
  while(!q.empty()){
    pair<int,int> cell1 = q.front();
    int ay = cell1.first;
    int ax = cell1.second;
    // cout << ax << ", " << ay << '\n';
    q.pop();

    // cout << q.front().first << q.front().second << '\n';
    pair<int,int> cell2 = q.front();

    int by = cell2.first;
    int bx = cell2.second;
    // cout << bx << ", " << by << '\n';
    q.pop();

    for(int i = ay; i < by; i++){
      for(int j = ax; j < bx; j++){
        visited[i][j] = true;
      }
    }

  }
  // cout << "finished marking the map" << '\n';

  // We find the left over areas
  int counter = 0;
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      if(!visited[i][j]){
        solve(j,i);
        counter++;
      }
    }
  }
  cout << counter << '\n';

  sort(area.begin(), area.end());
  for(int i = 0; i < area.size(); i++){
    cout << area[i] << ' ';
  }
}