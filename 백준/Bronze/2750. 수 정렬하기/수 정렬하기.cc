#include <iostream>
using namespace std;
int arr[1001];
int n;
int main() {
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[i]){
                swap(arr[i], arr[j]);
            }
        }
    }

    
    for(int i = 0; i < n; i++){
        cout << arr[i] << '\n';
    }
}