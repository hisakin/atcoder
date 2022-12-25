#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long

ll func(ll n, ll x){
  ll ret=1, i;
  for(i=0;i<n;i++){
    ret *= x;
    ret = ret % mod; 
  }
  return ret % mod;
}

int main(int argc, const char * argv[]) {

  ll N;cin >> N;
  ll i,ans;
  ans = (func(N,10) - func(N,9) - func(N,9) + func(N,8))%mod;
  ans = (ans + mod)%mod;

  cout << ans << endl;

}