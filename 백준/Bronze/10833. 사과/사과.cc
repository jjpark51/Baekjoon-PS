#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = 0;

    for(int i = 0; i < n; i++) {
        int student, apples;

        cin >> student >> apples;

        if(student <= apples) {
            sum += apples % student;
        }
        else {
            sum += apples;
        }
    }

    cout << sum;


}