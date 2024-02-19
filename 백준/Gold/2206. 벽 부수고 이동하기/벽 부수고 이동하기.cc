#include <iostream>
#include <string>
#include <vector>
#include <queue>
 
using namespace std;
 int n,m;
 int mat[1001][1001];

int shortestPath( int k)
{
    if (n == 1 && m == 1 && (mat[0][0] == 0 || k >= 1))
        return 1;
 
    vector<vector<vector<bool> > > visited(
        n, vector<vector<bool> >(
               m, vector<bool>(k + 1, false)));
    int steps = 1;
 
    queue<vector<int> > q;
    q.push({ 0, 0, k });
    int ar1[4] = { 1, -1, 0, 0 };
    int ar2[4] = { 0, 0, -1, 1 };
 
    while (!q.empty()) {
        int qSize = q.size();
 
        steps++;
        while (qSize--) {
            auto curr = q.front();
            int i = curr[0], j = curr[1], w = curr[2];
            q.pop();
            visited[i][j][w] = true;
            for (int dir = 0; dir < 4; dir++) {
                int new_x = i + ar1[dir];
                int new_y = j + ar2[dir];
                int new_k = w;
                if (new_x >= 0 && new_x < n && new_y >= 0
                    && new_y < m) {
                    if (mat[new_x][new_y] == 0
                        && !visited[new_x][new_y][new_k]) {
                        if (new_x == n - 1
                            && new_y == m - 1)
                            return steps;
                        q.push({ new_x, new_y, new_k });
                        visited[new_x][new_y][new_k] = true;
                    }
                    else if (mat[new_x][new_y] == 1
                             && new_k >= 1
                             && !visited[new_x][new_y]
                                        [new_k - 1]) {
                        if (new_x == n - 1
                            && new_y == m - 1)
                            return steps;
                        q.push({ new_x, new_y, new_k - 1 });
                        visited[new_x][new_y][new_k - 1]
                            = true;
                    }
                }
            }
        }
    }
    return -1;
}
 
int main()
{
    cin >> n >> m;
    int K = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char temp;
            cin >> temp;
            mat[i][j] = temp - '0';
        }
    }
 
    cout << shortestPath( K);
}