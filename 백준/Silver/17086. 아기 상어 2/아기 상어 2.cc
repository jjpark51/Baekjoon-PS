#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> space(N, vector<int>(M));
    vector<vector<int>> dist(N, vector<int>(M, -1)); // Initialize all distances to -1
    queue<pair<int, int>> q;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> space[i][j];
            if (space[i][j] == 1) {
                q.push({i, j});
                dist[i][j] = 0; // Distance to shark is 0
            }
        }
    }

    int max_distance = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int d = 0; d < 8; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                max_distance = max(max_distance, dist[nx][ny]);
                q.push({nx, ny});
            }
        }
    }

    cout << max_distance << endl;
}
