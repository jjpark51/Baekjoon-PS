#include <iostream>
#include <vector>

using namespace std;

vector<long long>v;

void solve(int start, int end){
    if(start >= end){
        return;
    }

    if(start == end - 1){
        cout << v[start] << '\n';
        return;
    }

    int index = start + 1;
    while(index < end){
        if(v[start] < v[index]){
            break;
        }
        index++;
    }
    solve(start + 1, index);
    solve(index, end);
    cout << v[start] << '\n';
}

int main() {
    long long tmp;

    while(cin >> tmp){
        v.push_back(tmp);
    }

    // for(int i = 0; i < v.size(); i++){
    //     cout << v[i] << ' ';
    // }
    // cout << '\n';

    solve(0, v.size());
}