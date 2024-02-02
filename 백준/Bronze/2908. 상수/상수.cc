#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    string a,b;
    cin >> a >> b;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int ra = stoi(a);
    int rb = stoi(b);

    cout << max(ra,rb) << endl;
}