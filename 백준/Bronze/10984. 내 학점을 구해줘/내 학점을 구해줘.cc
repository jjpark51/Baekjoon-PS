#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

int main() {
    int semester;
    cin >> semester;

    for(int i = 0; i < semester; i++){
        int subjectNum = 0;
        cin >> subjectNum;
        
        double sum = 0;
        int creditSum = 0;
        for(int j = 0; j  < subjectNum; j++){
            int credit = 0;
            double grade = 0;
            cin >> credit >> grade;
            creditSum += credit;


            sum += credit * grade;
        }
        // cout << creditSum << " " << (sum / creditSum);
        printf("%d %.1lf\n",creditSum, sum / creditSum);
    }


}