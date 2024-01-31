#include <stdio.h>
#include <queue>
#include <iostream>

using namespace std;
int main() {

    int N = 0;
    int K = 0;

    cin >> N >> K;

    queue<int> circle;

    for(int i = 1; i <= N; i++){
        circle.push(i);
    }
    queue<int> result;

    while(result.size() != N){
        for(int i = 0 ; i < K - 1; i++){
            int temp = 0;
            temp = circle.front();
            circle.pop();
            circle.push(temp);
        }

        result.push(circle.front());
        circle.pop();
    }
    cout << "<";
    for(int i = 0 ; i < N; i++){
        cout << result.front();
        if(i != N - 1){
            cout << ", ";
        }
        else if(i == N - 1){
            cout << "";
        }
        result.pop();
    }
    cout << ">";

   
}