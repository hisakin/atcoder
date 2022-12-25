#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;

vector<ll> memo;
vector<ll> A;

ll dp(ll i){
  if(i==1){
    return 1;
  }
  if(memo[i]!=-1){
    return memo[i];
  }

  ll m=0;
  ll max_j=0;
  ll dp_temp;
  for(ll j=0;j<A.size();j++){
    if(i<A[j]) continue;
    m = max(m,i - dp(i-A[j]));
  }
  return memo[i]=m;

}

int main(int argc, const char * argv[]) {
  ll N,K;cin >> N >> K;
  A.assign(K,0);
  for(ll i=0;i<K;i++){
    cin >> A[i];
  }

  memo.assign(N+1,-1);
  memo[1]=1;
  memo[0]=0;
  ll ans = dp(N);

  cout << ans << endl;

  return 0;
}