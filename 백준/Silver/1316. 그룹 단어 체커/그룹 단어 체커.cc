#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;


    vector<string> v(n);

    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int result = 0;
    int j;
    for(int i = 0; i< n; i++){
        int counter[27] = {0};
        for(j = 0; j < v[i].size(); j++){
            char c = v[i][j];

            if(counter[c - 'a'] == 0){
                counter[c - 'a']++;
            }
            else {
                if(c != v[i][j-1]){
                    // cout << "break here at " << c << endl;
                    break;
                }
            }
        }
        if(j == v[i].size()){
            // cout << v[i] << " is a group word " << endl;
            result++;
        }
        
    }
    cout << result;

}



    
