#include <iostream>
using namespace std;

int n;
int arr[1000001];
int tmp[1000001];

void merge(int st, int end){
    int mid = (st + end) / 2;
    int left = st;
    int right = mid;
    for(int i = st; i < end; i++){
        if(right == end){
            tmp[i] = arr[left];
            left++;
        }
        else if(left == mid){
            tmp[i] = arr[right];
            right++;
        }
        else if(arr[left] <= arr[right]){
            tmp[i] = arr[left];
            left++;
        }
        else{
            tmp[i] = arr[right];
            right++;
        }
    }
    for(int i = st; i < end; i++){
        arr[i] = tmp[i];
    }   
}
void mergeSort(int st, int end){
    if(end - st == 1){
        return;
    }
    int mid = (st + end) / 2;
    mergeSort(st, mid);
    mergeSort(mid, end);
    merge(st, end);

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        arr[i] = tmp;
    }

    
    mergeSort(0,n);
    for(int i = 0; i < n ; i++){
        cout << arr[i] << ' ';
    }
}