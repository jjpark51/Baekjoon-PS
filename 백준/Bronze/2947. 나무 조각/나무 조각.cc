#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {

    vector<int> input;

    for(int i = 0; i < 5; i++){
        int tmp;
        cin >> tmp;
        input.push_back(tmp);
    }

    int flag =0;

    for(int i = 0; i < input.size() - 1; i++){
        flag = 0;

        for(int j = 0; j < input.size() - 1; j++){
            if(input[j] > input[j + 1]){
                swap(input[j], input[j+1]);

                for(int i = 0; i < input.size(); i++){
                    cout << input[i] << " ";
                }
                cout << "\n";
                flag = 1;
            }

        }

        if(flag == 0){
            break;
        }


    }
  
}
