#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {

  ll N; cin >> N;
  vector<ll> A(N);
  for(ll i=0;i<N;i++){
    cin >> A[i];
  }

  ll ans=0;
  for(ll l=0;l<N;l++){
    ll minv = A[l];
    for(ll r=l;r<N;r++){
      if(minv>A[r]) minv = A[r];
      ans = max(ans,minv*(r-l+1));
    }
  }
  cout << ans << endl;
  return 0;
}