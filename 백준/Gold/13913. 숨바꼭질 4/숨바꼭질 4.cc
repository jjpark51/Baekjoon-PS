#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;

bool visited[100001];
long long path[100001];

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

            if(left <= 100000 &&  left >= 0 && !visited[left]){
                q.push(left);
                path[left] = x;
                visited[left] = true;
            }
            if(middle >= 0 && middle <= 100000 && !visited[middle]){
                q.push(middle);
                path[middle] = x;
                visited[middle] = true;
            }
            if(right >= 0 && right <= 100000 && !visited[right]){
                q.push(right);
                path[right] = x;
                visited[right] = true;
            }
        }
        
    }

}

int main() {
    long long n, k;
    cin >> n >> k;

    bfs(n, k);
    cout << endl;
    
    stack<int> st;
    st.push(k);
    while (k != n) {
        k = path[k];
        st.push(k);
    }

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

}