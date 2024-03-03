#include <iostream>
#include <stack>
#include <queue>
using namespace std;

long long n;
int main() {
    cin >> n;
    queue<long long>q;

    for(int i = 1; i <= n; i++){
        q.push(i);
    }

    while(q.size() != 1){
        q.pop();
        long long current = q.front();
        q.pop();
        q.push(current);
    }

    cout << q.front();

}