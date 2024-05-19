#include <iostream>
#include <vector>

using namespace std;
int n;

int main() {

    cin >> n;
    int result = 0;

    for(int i = 0; i < n; i++){
        int v, e;
        cin >> v >> e;

        result = 2 + e - v;
        cout << result << '\n';
    }


}