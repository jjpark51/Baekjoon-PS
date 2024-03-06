#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int l,n,m;
char map[31][31][31];
int visited[31][31][31];
int dx[6] = {0,0,0,0,1,-1};
int dy[6] = {1,-1,0,0,0,0};
int dz[6] = {0,0,1,-1,0,0};

void solve(int a, int b, int c, int d, int e, int f) {
  queue<pair< pair<int,int>, int>>q;
  q.push({{a,b},c});

  while(!q.empty()){
    pair<int,int> cell = q.front().first;
    int x = cell.first;
    int y = cell.second;
    int z = q.front().second;
    q.pop();

    // if(x == d && y == e && z == f){
    //   cout <<  "Escaped in " << 0 << " minute(s).";
    //   return;
    // }

    for(int i = 0; i < 6; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      int nz = z + dz[i];

      if(nx >= 0 && nx < n && ny >= 0 && ny < m && nz >= 0 && nz < l && 
          visited[nx][ny][nz] == 0 && map[nx][ny][nz] != '#'){
            visited[nx][ny][nz] = visited[x][y][z] + 1;
            q.push({{nx,ny},nz});
            if(map[nx][ny][nz] == 'E'){
              cout << "Escaped in " << visited[nx][ny][nz] - 1 << " minute(s)." << '\n';
              return;
            }
          }
    }
  }
  cout << "Trapped!" << '\n';
}

int main(){
  int a,b,c,d,e,f;

  while(1){
    cin >> l >> n >> m;
    if(l == 0 && n == 0 && m == 0){
      break;
    }
    for(int lvl = 0; lvl < l; lvl++){
      // cout << lvl <<  " level" <<'\n';
      for(int i = 0; i < n ; i++){
        for(int j = 0;  j < m; j++){
          char tmp;
          cin >> tmp;
          map[i][j][lvl] = tmp;
          if(tmp  == 'S'){
            // q.push({{i,j},lvl});
            visited[i][j][lvl] = 1;
            a = i;
            b = j; 
            c = lvl;
            // cout << "The starting point is " << i << " " << j << " " << lvl<<'\n';
          }
          else if(tmp == 'E'){
            d = i;
            e = j;
            f = lvl;
          }
        }
      }
    }

    solve(a,b,c,d,e,f);

// Since there are multiple tesst cases, we reset map and visited array
    memset(visited, 0 , sizeof(visited));
    memset(map, ' ' , sizeof(map));

    
  }
}