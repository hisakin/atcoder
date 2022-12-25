#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;

ll MODCONST = 998244353;
ll N,M,K; 
vector<ll> A;
// vector<vector<ll>> F;
vector<vector<ll>> MEMO;

ll dp(ll n, ll k){
  if(MEMO[n][k]!=-1) return MEMO[n][k];
  ll s = 0;
  for(ll i=1;i<k;i++){
    s += dp(n-1,i);
    s = s % MODCONST;
  }
  return MEMO[n][k] = s;
}

int main(int argc, const char * argv[]) {

  cin >> N >> M >> K;
  A.resize(N+1);
  MEMO = vector<vector<ll>>(N+1,vector<ll>(K+1,-1));
  for(ll i=1;i<=K;i++){
    ll temp = 1;
    if(i>M) temp=0;
    MEMO[1][i]=temp;
  }

  for(ll i=1;i<=K;i++){
    dp(N,i);
  }

  ll ans=0;
  for(ll i=1;i<=K;i++){
    ans += MEMO[N][i];
    ans = ans % MODCONST;
  }

  cout << ans << endl;

  // for(ll i=1;i<=N;i++){
  //   for(ll j=1;j<=K;j++){
  //     cout << "MEMO[" << i << "][" << j << "]=" << MEMO[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  return 0;
}