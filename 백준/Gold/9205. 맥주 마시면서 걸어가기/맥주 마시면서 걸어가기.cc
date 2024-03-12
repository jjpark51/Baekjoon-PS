#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int t,n;
bool visited[103] = {false};
// bool visited[103] = {false};

// void solve() {
//     bool visited[103];
//     for(int i = 0; i < v.size(); i++){
//         cout << v[i].firq << " , " << v[i].second << '\n';
//     }
//     queue<pair<pair<int,int>,int>>q;
//     q.push({{v[0].firq, v[0].second},0});
//     visited[0] = true;

//     while(!q.empty()){
//         pair<int,int> cell = q.front().firq;
//         int x = cell.firq;
//         int y = cell.second;
//         int node = q.front().second;
//         q.pop();

//         for(int i = 1; i < v.size(); i++){
//             int nx = v[i].firq;
//             int ny = v[i].second;
//             int nz = i;
//             int diq = abs(x - nx) + abs(y - ny);

//             if(!visited[i] && diq <= 1000){
//                 q.push({{nx, ny}, i});
//                 visited[i] = true;
//             }
//         }
//     }
// }

int main() {

    cin >> t;

    for(int i = 0; i < t; i++){
        vector<pair<int,int>>v;
        cin >> n;

        pair<int,int> home, festival;
        int sx,sy;
        cin >> sx >> sy;
        home.first = sx;
        home.second = sy;

        for(int i = 0; i < n ; i++){
            int a,b;
            cin >> a >> b;
            v.push_back({a,b});
        }

        int ex, ey;
        cin >> ex >> ey;
        festival.first = ex;
        festival.second = ey;

        bool check = false;

        // solve();
        // for(int i = 0; i < v.size(); i++){
        //     cout << v[i].firq << " , " << v[i].second << '\n';
        // }
        queue<pair<int,int>>q;
        q.push({home.first, home.second});

        while(!q.empty()){
            pair<int,int> cell = q.front();;
            int x = cell.first;
            int y = cell.second;
            q.pop();

            for(int i = 0; i < v.size(); i++){
                int nx = v[i].first;
                int ny = v[i].second;
                int dist = abs(x - nx) + abs(y - ny);

                if(!visited[i] && dist <= 1000){
                    // cout << "Pushed: " << nx << " " << ny << " " << i << '\n';
                    q.push({nx, ny});
                    visited[i] = true;
                }

            }
            if(abs(x - festival.first) + abs(y - festival.second) <= 1000){
                    check = true;
                    break;
                }
        }
        if(check == true){
            cout <<"happy" << '\n';
        }
        else{
            cout <<"sad" << '\n';
        }
        memset(visited, false, sizeof(visited));

    }
}