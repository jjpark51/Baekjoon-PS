#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
   int hour, minutes;

   cin >> hour >> minutes;

   int total_time = hour * 60 + minutes;

//    if ( total_time < 45 ) {
//         total_time = 60 - (minutes - 45);
//         hour = 23 ;
//    }
    if( total_time < 45) {
        minutes = 60 + (minutes - 45);
        hour = 23 ;
        
    }
   else {
        total_time -= 45;
        hour = total_time / 60 ;
        minutes = total_time % 60;
        // cout << total_time << '\n';
   }



    cout << hour << " " <<  minutes << '\n';

}