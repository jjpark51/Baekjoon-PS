#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int cmp[100001];
int n,m;
void binary_search(int x  ){
   int left = 0, mid = 0, right = n - 1;

    while (left <= right) {
        mid = (left + right) / 2;

        if (cmp[mid] == x) {
            cout << 1 << "\n";
            return;
        } else if (cmp[mid] > x) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << 0 << '\n';
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> a;

    cin >> n;

    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    sort(a.begin(), a.end());
    cin >> m;

    for(int i = 0; i < n; i++){
        cmp[i] = a[i];
    }

    vector<int> b;
    for(int i = 0; i < m; i++){
        int tmp;
        cin >> tmp;
        b.push_back(tmp);
    }

    for(int i = 0; i < m; i++){
        binary_search(b[i]);
    }



}
