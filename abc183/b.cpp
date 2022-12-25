#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {



  long double Sx, Sy, Gx, Gy; cin >> Sx >> Sy >> Gx >> Gy;

  long double ans = (Sx*Gy + Gx*Sy)/(Sy+Gy);

  cout << fixed << setprecision(10)<< endl;
  cout << ans << endl;


}