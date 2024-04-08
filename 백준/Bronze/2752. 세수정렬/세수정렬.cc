#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int a, b, c;

    cin >> a >> b >> c;
    vector<int> v;

    v.push_back(a);
    v.push_back(b);
    v.push_back(c);

    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }

}