#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int board[101][101];
int dist[101][101];
int calcX[4] = { 0,0,1,-1 };
int calcY[4] = {1,-1, 0,0};

void bfs() {
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	dist[0][0] = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + calcX[i];
			int ny = y + calcY[i];
			if (nx <0 || ny<0 || nx>=M || ny>=N ) continue;
			if (board[nx][ny] == 1) {
				if (dist[nx][ny] > dist[x][y] + 1) {
					dist[nx][ny] = dist[x][y] + 1;
					q.push({ nx,ny });
				}
			}
			else if(board[nx][ny]==0) {
				if (dist[nx][ny] > dist[x][y]) {
					dist[nx][ny] = dist[x][y];
					q.push({ nx,ny });
				}
			}
		}
	}

}

int main() {
	cin >> N >> M;
	string str;
	for (int i = 0; i < M; i++) {
		cin >> str;
		for (int j = 0; j < N; j++) {
			dist[i][j] = 987654321;
			board[i][j] = str[j] - '0';
		}
	}
	bfs();
	cout << dist[M - 1][N - 1];
}