#include <iostream>
#include <string>
#include <vector>
#include <queue>
 
using namespace std;
 int n,m;
 int mat[1001][1001];
 bool visited[1001][1001][11] = {false};
 
 int calcX[4] = {0,0,-1,1};
 int calcY[4] = {1,-1, 0,0};

// 1. 3D visit array
// 2. queue that contains adjX, adjY, no. of walls we can destroy
// 3. pop front eleement from the queue, and explore all 4 coords
// 4. if cell is 0 & not visited, explore all directions, push all nonvisted cells from this cells into the queue, mark as visited
// 5. if cell is 1 & not visited & we can destroy this wall, push all nonvisited cells into the queue
// 6. after each iteration, increment the step value
// 7. 

int shortestPath( int k)
{
    if (n == 1 && m == 1 && (mat[0][0] == 0 || k >= 1))
        return 1;
 
    int steps = 1;
 
    queue<vector<int>> q;
    // The number of walls that we can destroy
    q.push({ 0, 0, k });
 
    while (!q.empty()) {
        int qSize = q.size();
 
        steps++;
        for(int i = 0; i < qSize; i++){
            auto cell = q.front();
            int x = cell[0], y = cell[1], z = cell[2];
            q.pop();
            visited[x][y][z] = true;
            for (int j = 0; j < 4; j++) {
                int new_x = x + calcX[j];
                int new_y = y + calcY[j];
                int new_k = z;
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
                        visited[new_x][new_y][new_k - 1] = true;
                    }
                }
            }
        }
    }
    return -1;
}
 
int main()
{
    int k;
    cin >> n >> m >> k;
    

    for(int i = 0; i < n; i++
    ){
        for(int j = 0; j < m; j++){
            char temp;
            cin >> temp;
            mat[i][j] = temp - '0';
        }
    }
 
    cout << shortestPath( k);
}