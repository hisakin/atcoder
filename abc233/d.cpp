#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {

  ll N, K; cin >> N >> K;
  vector<ll> A(N);
  for(ll i=0;i<N;i++){
    cin >> A[i];
  }

  vector<ll> S(N+1);
  S[0]=0;
  for(ll i=1;i<N+1;i++){
    S[i]=S[i-1]+A[i-1];
  }

  map<ll,ll> MAP;

  ll ans=0;
  for(ll r=0;r<N+1;r++){
    ans += MAP[S[r]];
    MAP[S[r]+K]++;
  }

  cout << ans << endl;
  return 0;
}