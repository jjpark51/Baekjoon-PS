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



    for(int i = 0; i < input.size() - 1; i++){

        for(int j = 0; j < input.size() - 1; j++){
            if(input[j] > input[j + 1]){
                int tmp = input[j];
                input[j] = input[j+1];
                input[j+1] = tmp;

                for(int i = 0; i < input.size(); i++){
                    cout << input[i] << " ";
                }
                cout << "\n";
            }

        }


    }
  
}
