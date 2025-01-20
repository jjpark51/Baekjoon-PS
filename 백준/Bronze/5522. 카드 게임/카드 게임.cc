#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

int main() {
    vector<int> v;
    for(int i = 0; i <5; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    int sum = 0;

    for(int i = 0; i < 5; i++){
        sum += v[i];
    }

    cout << sum;

}