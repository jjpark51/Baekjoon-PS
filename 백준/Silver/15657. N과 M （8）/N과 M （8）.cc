#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,m;
vector<int> arr;
// vector<int> result;
int result[10];
int visited[10001];

void solve(int k) {
    // Our base condition: if k meets m, we print and return
    if(k == m){
        // We simply just print out the array
        for(int i = 0; i < m; i++){
            cout << result[i] << " ";
            // result.clear();
        }
        cout << '\n';
        return;
    }
    for(int i = 0; i < n; i++){
        if(k == 0){
            result[0] = arr[i];
            solve(1);
        }
        else if(result[k - 1] <= arr[i]){
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
        arr.push_back(tmp);
    }

    sort(arr.begin(), arr.end());

    solve(0);



}