#include <iostream>
#include <math.h>
using namespace std;

int main() {
  int a,b,c,d,e;

  cin >> a >> b >> c >> d >> e;

  int result = pow(a,2) + pow(b,2) + pow(c,2) + pow(d,2) + pow(e,2);

  cout << result % 10;
}