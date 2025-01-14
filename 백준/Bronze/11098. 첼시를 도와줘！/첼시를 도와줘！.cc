#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int p;
        vector<pair<int, string>> result;
        cin >> p;



        for(int j = 0; j < p; j++){
            string player;
            int price;

            cin >> price >> player;
           

            result.push_back(make_pair(price, player));
        }
        sort(result.begin(), result.end());
        cout << result[result.size() - 1].second << '\n';
    }
}