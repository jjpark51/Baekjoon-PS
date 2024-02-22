#include <iostream>
using namespace std;

int n, x;
int arr[10001];
int main() {
    cin >> n >> x;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++){
        if(arr[i] < x){
            cout << arr[i] << " ";
        }
    }

}