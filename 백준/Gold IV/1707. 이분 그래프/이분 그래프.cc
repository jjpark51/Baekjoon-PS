#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

vector<long long>graph[20001];
int color[20001];

void bfs(int x) {
    queue<long long> q;
    q.push(x);
    color[x] = 1;

    while (!q.empty()) {
        long long current = q.front();
        q.pop();

        for (int i = 0; i < graph[current].size(); i++) {
            if (color[graph[current][i]] == 0) {
                q.push(graph[current][i]);

                if (color[current] == 1) {
                    color[graph[current][i]] = 2;
                } else if (color[current] == 2) {
                    color[graph[current][i]] = 1;
                }
            }
        }
    }
}

int main() {
    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
        int flag = 0;
        long long n, e;
        cin >> n >> e;

        for (int i = 0; i < e; i++) {
            long long a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }


        for (int i = 1; i <= n; i++) {
            if (color[i] == 0) {
                bfs(i);
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                if (color[i] == color[graph[i][j]]) {
                    flag = 1;
                    break;
                }
            }
        }

        if (flag == 1) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }

        memset(color, 0, sizeof(color));
        memset(graph, 0, sizeof(graph));
    }

}
