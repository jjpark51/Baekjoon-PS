#include <iostream>
#include <vector>

using namespace std;
int n;

int main() {

cin >> n;

    for(int i = 0; i < n; i++){
        int a, b;

        cin >> a >> b;

        int x = a / b;
        int y = a % b;

        cout << "You get " << x << " piece(s) and your dad gets " << y << " piece(s)." << '\n';
    }

}