#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool visited[100001];

void bfs(int n, int k) {
    queue<long long>q;
    q.push(n);
    visited[n] = true;
    long long depth = 0;

    while(!q.empty()){

        long long levelSize = q.size();
        depth++;

        for(int i = 0; i < levelSize; i++){
            long long x = q.front();
            if(x == k){
                cout << depth - 1;
                return;
            }
            q.pop();

            int left = x - 1;
            int middle = x + 1;
            int right = x * 2;

            if( left >= 0 && !visited[left]){
                q.push(left);
                visited[left] = true;
            }
            if(middle <= 100000 && !visited[middle]){
                q.push(middle);
                visited[middle] = true;
            }
            if(right <= 100000 && !visited[right]){
                q.push(right);
                visited[right] = true;
            }
        }
        
    }

}

int main() {
    long long n, k;
    cin >> n >> k;

    bfs(n, k);

}