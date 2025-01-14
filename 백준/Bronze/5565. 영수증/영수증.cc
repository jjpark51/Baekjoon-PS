#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

int main() {

    int total;
    cin >> total;

    int sum = 0;

    for(int i = 0; i < 9; i++){
        int tmp;
        cin >> tmp;
        sum += tmp;
    }

    cout << total - sum;
}