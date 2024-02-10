#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
   int n;
   int k;
   cin >> n >> k;

   queue<int> q;
   vector<int> result;

   for(int i = 1; i <= n ; i++){
    q.push(i);
   }

    int counter = 1;
   while(result.size() != n) {
        if(counter == k){
            result.push_back(q.front());
            q.pop();
            counter = 1;
        }
        else {
            counter++;
            int temp;
            temp = q.front();
            q.pop();
            q.push(temp);
        }

   }

    cout << "<";
   for(int i = 0; i < n; i++){
        if(i == n - 1){
            cout << result[i] << ">";
        }
        else {
            cout << result[i] <<", ";
        }
   }

}



    
