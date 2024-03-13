#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
int n;
queue<pair<long long, long long>>q;
vector<long long>v;
int main() {
    cin >> n;
    v.push_back(-1);
    for(int i = 1; i <= n ;i++){
        long long tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    // long long start = v[0];
    // q.push({start, 1});
    // for(int i = 1; i < n; i++){
    //     if(v[i] != start){
    //         q.push({v[i], i+1});
    //         start = v[i];
    //     }
    // }
    long long index= -1;
    long long current = v[n];

    stack<long long>st;

    for(int i = n; i > 0; i--){
        if(v[i] == current){
            st.push(index);
        }
        else {
            st.push(i + 1);
            index = i + 1;
            current = v[i];
        }
    }

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    // for(int i = 2; i <=n ;i++){
    //     if(v[i] != v[1]){
    //         index = i;
    //         break;
    //     }
    // }
    // queue<int>q;

    // // for(int i = 1; i < index; i++){
    // //     q.push(index);
    // // }

    // long long current = v[1];
    // long long past = 0;

    // for(int i = 1; i <= n; i++){
    //     if(current == v[i]){
    //         q.push(index);
    //     }
    //     else{

    //     }
    // }

    // while(!q.empty()){
    //     pair<long long, long long> cell = q.front();
    //     long long x = cell.first;
    //     long long y = cell.second;
    //     cout << q.front().first << " " << q.front().second << " ";
    //     cout << '\n';
    //     q.pop();
    //     if(q.empty()){

    //     }
    //     else {
    //         pair<long long, long long> bcell = q.front();
    //         long long nx = bcell.first;
    //         long long ny = bcell.second;
    //         for(int i = 0; i < ny - y; i++){
    //             cout << ny << " ";
    //         }
    //     }

    // }



    


    


    // cin >> n;
    // vector<long long>v;
    // long long tmp;
    // v.push_back(-1); // dummy value
    // for(int i = 0; i < n; i++){
    //     cin >> tmp;
    //     v.push_back(tmp);
    // }

    // for(int i = 1; i <= n; i++){
    //         long long minNum = v[i];
    //         long long minIndex = -1;
    //     for(int j = i + 1; j <= n; j++){
    //         if(v[j] != v[i]){
    //             minIndex = j;
    //             cout << j << " ";
    //             break;
    //         }
    //     }
    //     if(minIndex == -1){
    //         cout << "-1 ";
    //     }
    // }
}