#include <iostream>
#include <vector>
using namespace std;
int n,m;
int a[1000001];
int b[1000001];
int result[2000002];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        a[i] = tmp;
    }
    for(int i = 0; i < m; i++){
        int tmp;
        cin >> tmp;
        b[i] = tmp;
    }

    int top = 0;
    int bottom = 0;

    int index = 0;
    // while(1){
    //     if(a[top] <= b[bottom] && top <= n -1){
    //         result[index] = a[top];
    //         // result.push_back(a[top]);
    //         top++;
    //     }
    //     else if(a[top] > b[bottom] && bottom <= m - 1){
    //         // result.push_back(b[bottom]);
    //         result[index] = b[bottom];
    //         bottom++;
    //     }
    //     else if(top == n){
    //         // result.push_back(b[bottom]);
    //         result[index] = b[bottom];
    //         bottom++;
    //     }
    //     else if(bottom == m){
    //         result[index] = a[top];
    //         top++;
    //     }
    //     if(top == n && bottom == m){
    //         break;
    //     }
    //     index++;
        

    // }
    for(int i = 0; i < n + m; i++){
        if(bottom == m){
            result[i] = a[top++];
        }
        else if(top == n){
            result[i] = b[bottom++];
        }
        else if(a[top] <= b[bottom]){
            result[i] = a[top++];
        }
        else {
            result[i] = b[bottom++];
        }
    }

    for(int i = 0; i < n + m; i++){
        cout << result[i] << " ";
    }

}