#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {


  ll N,Q; cin >> N  >> Q;
  vector<ll> a(N);
  for(ll i=0;i<N;i++) cin >> a[i];

  map<ll,vector<ll>> MAP;

  for(ll i=0;i<N;i++){
    MAP[a[i]].push_back(i);
  }

  for(ll i=0;i<Q;i++){
    ll x,k; cin >> x >> k;
    k--;
    if(MAP[x].size()<=k){
      cout << "-1" << endl;
      continue;
    }
    ll ans = MAP[x][k];
    cout << ans+1 << endl;
  }



  return 0;
}