#include <iostream>
using namespace std;
int n,m;
int arr[10];
int visited[10];

void solve(int k) {
    // Our base condition: if k meets m, we print and return
    if(k == m){
        // We simply just print out the array
        for(int i = 0; i < m; i++){
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            if(k > 0 && arr[k-1] < i){
                arr[k] = i;
                visited[i] = 1;
                solve(k+1);
                visited[i]= 0;
                }
            else if(k == 0){
                arr[0] = i;
                visited[i] = 1;
                solve(k+1);
                visited[i] = 0;
            }
            
        }
    }
}

int main() {
    cin >> n >> m;
    solve(0);



}