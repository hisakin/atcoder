#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
const ll mod = 998244353;

ll pow(ll x, ll n){
  if(n==0) return 1;
  ll ans = 1;
  for(ll i=0;i<n;i++){
    ans = ans * x;
  }
  return ans;
}

int main(int argc, const char * argv[]) {

  ll N; cin >> N;
  ll digit = log10(N)+1;
  ll cnt = digit;
  ll temp_N = N;
  ll sum = 0;
  while(cnt>=1){
    ll dist = temp_N - pow(10,cnt-1) + 1;
    cout << "dist=" << dist << "  cnt=" << cnt << endl;
    ll dist_sum = ((dist%mod)*((dist+1)%mod)/2)%mod;
    sum += dist_sum % mod;
    cnt--;
    temp_N = pow(10,cnt-1) - 1;
  }

  cout << sum << endl;






  return 0;
}