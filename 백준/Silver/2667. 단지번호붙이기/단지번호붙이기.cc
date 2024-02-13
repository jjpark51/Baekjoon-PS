#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int map[26][26];
bool visited[26][26] = {false};
int calcX[4] = {-1, 1, 0, 0};
int calcY[4] = {0, 0, -1, 1};
int n;
vector<long long> result;

void bfs(int i, int j) {
    queue<pair<long, long>> q;
    q.push({i, j});
    visited[i][j] = true;
    int counter = 1;

    while (!q.empty()) {
        pair<long, long> cell = q.front();
        int x = cell.first;
        int y = cell.second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int adjX = x + calcX[k];
            int adjY = y + calcY[k];

            if (adjX >= 0 && adjX < n && adjY >= 0 && adjY < n
                && !visited[adjX][adjY] && map[adjX][adjY] == 1) {
                q.push({adjX, adjY});
                visited[adjX][adjY] = true;
                counter++;
            }
        }
    }
    result.push_back(counter);
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 1 && !visited[i][j]) {
                bfs(i, j);
            }
        }
    }

    cout << result.size() << endl;

    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
}