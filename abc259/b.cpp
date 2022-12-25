#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {


  long double a, b, d; cin >> a >> b >> d;

  if(a==0.0 && b ==0.0){
    cout << "0" <<" " << "0" << endl;
  }else{


  long double ans_x = cos(d*M_PI/180.0)*a - sin(d*M_PI/180.0)*b;
  long double ans_y = sin(d*M_PI/180.0)*a + cos(d*M_PI/180.0)*b;
  
  cout << fixed << setprecision(20);
  cout << ans_x << " " << ans_y << endl;
  }

  return 0;

}