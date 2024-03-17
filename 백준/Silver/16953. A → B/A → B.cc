#include <iostream>
#include <queue>
using namespace std;
long long a,b;

void solve(long long a){
    queue<int> q;
    q.push(a);
    int depth = 1;

    while(!q.empty()){
        long long qSize = q.size();

        for(int i = 0; i < qSize; i++){

            long long x = q.front();
            q.pop();

            long long ax = 2 *x;
            long long bx = 10 *x + 1;

            if(ax == b || bx == b){
                
                cout << ++depth;
                return;
            }
            if(ax <= b){
                q.push(ax);
            }
            if(bx <= b){
                q.push(bx);
            }

        }
        depth++;

    }
    cout << -1 << '\n';
}

int main() {
    cin >> a >> b;

    solve(a);
}