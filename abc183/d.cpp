#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {

  ll N,W; cin >> N >> W;
  vector<ll> S(N),T(N),P(N);
  ll Tmax=0;
  for(ll i=0;i<N;i++){
    cin >> S[i] >> T[i] >> P[i];
    Tmax = max(Tmax,T[i]);
  }
  vector<ll> VAL(Tmax+1,0);
  for(ll i=0;i<N;i++){
    VAL[S[i]]+=P[i];
    VAL[T[i]]-=P[i];
  }

  bool ans=true;
  ll cnt=0;
  for(ll i=0;i<N;i++){
    cnt += VAL[i];
    if(cnt>W){
      ans=false;
      break;
    }
  }
  if(ans) cout << "Yes" << endl;
  else  cout << "No" << endl;

  return 0;
}