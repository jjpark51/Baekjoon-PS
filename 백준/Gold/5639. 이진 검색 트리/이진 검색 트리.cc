#include <iostream>
#include <vector>

using namespace std;

vector<int>v;

int preIndex; 
void solve(int start, int end){
    if(start > end){
        return;
    }

    int root = v[start];
    int rightStart = end + 1;

    for(int i = start + 1; i <= end; i++){
        if(v[i] > root){
            rightStart = i;
            break;
        }
    }

    solve(start + 1, rightStart - 1);
    solve(rightStart, end);
    cout << root << " ";
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

    solve(0, v.size() - 1);
}