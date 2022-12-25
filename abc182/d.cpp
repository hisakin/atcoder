#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {

  ll N; cin >> N;
  vector<ll> A(N);
  for(ll i=0;i<N;i++) cin >> A[i];
  vector<ll> S(N); S[0]=A[0];
  vector<ll> Smax(N); Smax[0]=A[0];
  for(ll i=1;i<N;i++){
    S[i]=S[i-1]+A[i];
    Smax[i]=max(Smax[i-1],S[i]);
  }

  vector<ll> INITV(N,0);
  for(ll i=1;i<N;i++){
    INITV[i]=INITV[i-1]+S[i-1];
  }

  ll ans = 0;
  for(ll i=0;i<N;i++){
    ans = max(ans,Smax[i]+INITV[i]);
  }
  cout << ans << endl;
  return 0;
}