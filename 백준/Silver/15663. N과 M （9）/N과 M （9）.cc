#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,m;
vector<int> arr;
// vector<int> result;
int result[10];
int visited[10];

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
    int tmp = 0;
    // How do we get back to the first element?
    for(int i = 1; i <= n; i++){

            // if(k == 0 && arr[i-1] != arr[i]){
            //     result[0] = arr[i];
            //     visited[i] = 1;
            //     solve(1);
            //     visited[i] = 0;
            // }
            if(visited[i] == 0 && arr[i] != tmp){
                result[k] = arr[i];
                tmp = result[k];
                visited[i] = 1;
                solve(k+1);
                // if(i != n  && arr[i+1] == arr[i]){
                //     // k--;
                //     i++;
                //     continue;
                // }
                visited[i] = 0;
            }
        
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    arr.push_back(-1);
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    
    sort(arr.begin(), arr.end());

    // for(int i = 0; i < arr.size(); i++){
    //     cout << arr[i] << " ";
    // }
    // cout << '\n';
    solve(0);



}