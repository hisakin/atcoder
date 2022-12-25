#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {


  ll N, M; cin >> N >> M;
  vector<ll> A(N);
  for(ll i=0;i<N;i++) cin >> A[i];

  vector<ll> S(N+1);
  S[0]=0;
  for(ll i=1;i<N+1;i++){
    S[i] = S[i-1] + A[i-1];
  }

  ll current=0;
  for(ll i=0;i<M;i++){
    current+=(i+1)*A[i];
  }

  ll ans=0;
  ans = current;

  for(ll i=1;i<N-M+1;i++){
    ll nextV = current + M*A[i+M-1] - (S[i+M-1]-S[i-1]);
    ans = max(ans,nextV);
    current = nextV;
  }

  cout << ans << endl;
  
  return 0;
}