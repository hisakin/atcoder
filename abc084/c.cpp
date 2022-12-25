#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {

  ll N; cin >> N;
  vector<ll> C(N-1),S(N-1),F(N-1);
  for(ll i=0;i<N-1;i++){
    cin >> C[i] >> S[i] >> F[i];
  }

  vector<ll> ans(N,0);
  for(ll i=0;i<N-1;i++){
    ll cnt_i = 0;
    ll t=0;
    for(ll j=i;j<N-1;j++){
      if(j==i){
        t = S[j]+C[j];
      }else if(t <= S[j]){
        t = S[j]+C[j];
      }else{
        t = S[j] + ((t - S[j] + F[j] - 1)/F[j]) * F[j] + C[j];
      }
    }
    ans[i]=t;
  }

  for(ll i=0;i<N;i++){
    cout << ans[i] << endl;
  }
  return 0;
}