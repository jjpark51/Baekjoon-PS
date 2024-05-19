#include <iostream>
#include <vector>

using namespace std;
int n;

int main() {

cin >> n;

    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        int result = 0;
        result = a + b;
        cout << "Case " << i + 1 << ": ";
        cout << result << '\n';
    }

}