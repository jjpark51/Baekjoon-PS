#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int arr[10];
int result[10];
int visited[10];


void solve(int k){
    if(k ==m){
        for(int i = 0; i < m; i++){
            cout << result[i] << " ";
        }
        cout << '\n';
        return;
    }

    for(int i = 0; i < n; i++){
        // if(visited[i] == 0){
            if(k == 0 && arr[i] != result[0]){
               for(int i = 0; i < m; i++){
                    result[i] = 0;
                }
                result[0] = arr[i];
 
                solve(1);
            }
            if(k > 0 && result[k-1] <= arr[i] && arr[i - 1] != arr[i]){
                result[k] = arr[i];
                solve(k+1);
            }

    }


}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        arr[i] = tmp;
    }
    
    sort(arr, arr + n);
    // cout << "Answer: " << '\n';
    solve(0);


}