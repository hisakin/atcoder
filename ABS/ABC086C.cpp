#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {

  ll N; cin >> N;
  vector<ll> t(N+1),x(N+1),y(N+1);
  t[0]=0;
  x[0]=0;
  y[0]=0;
  for(ll i=0;i<N;i++){
    cin >> t[i+1];
    cin >> x[i+1];
    cin >> y[i+1];
  }

  bool ans=true;
  for(ll i=0;i<N;i++){
    ll t_dist = t[i+1] - t[i];
    ll xy_dist = abs(x[i+1]-x[i])+abs(y[i+1]-y[i]);
    if(t_dist < xy_dist){
      ans = false;
      break;
    }
    if((t_dist - xy_dist)%2 == 1){
      ans = false;
      break;
    }
  }

  if(ans){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }





  return 0;
}