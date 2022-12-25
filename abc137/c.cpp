#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {

  ll N; cin >> N;
  vector<string> S(N);
  for(ll i=0;i<N;i++){
    cin >> S[i];
    sort(S[i].begin(),S[i].end());
  }
  sort(S.begin(),S.end());

  ll ans=0;
  map<string,ll> CNTMAP;
  ll cnt=1;
  for(ll i=0;i<N;i++){
    CNTMAP[S[i]]++;
  }

  for(auto [key,value] : CNTMAP){
    ans+=value*(value-1)/2;
  }
  cout << ans << endl;
  return 0;
}