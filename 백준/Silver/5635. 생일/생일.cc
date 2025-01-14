#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

int main() {
    int n;
    vector<pair<int, string>> result;

    cin >> n;

    for(int i = 0; i < n; i++){
        string name;
        int day;
        int month;
        int year;

        cin >> name >> day >> month >> year;

        int age = ((2010 - year) * 365) + (12 -month)*31 + (31 - day);

        result.push_back(make_pair(age, name)); 
    }

    sort(result.begin(), result.end());

    cout << result[0].second << '\n';
    cout << result[n-1].second << '\n';

}