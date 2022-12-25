#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {


  ll N, Y; cin >> N >> Y;
  ll flag = false;

  ll ans_x,ans_y,ans_z;
  
  for(ll x=0;x <= N; x++){
    for(ll y=0;y<=N-x;y++){
      ll z = N - x - y;
      if(10000*x + 5000*y + 1000*z == Y){
        flag=true;
        ans_x = x; ans_y = y; ans_z = z;
        break;
      }
    }
  }

  if(flag){
    cout << ans_x << " " << ans_y << " " << ans_z << endl;
  }else{
    cout << "-1" << " " << "-1" << " " << "-1" << endl;
  }




  return 0;
}