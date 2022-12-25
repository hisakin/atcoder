#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;

ll MODCONST = 998244353;

vector<vector<ll>> MEMO;

ll dp(ll N, ll kind){
  cout << "N:" << N << "  kind:" << kind << endl;
  if(MEMO[N][kind]!=-1) return MEMO[N][kind];

  ll ans=0;
  for(ll i=-1;i<=1;i++){
    ll nextkind = kind + i;
    if(nextkind==0 || nextkind==10) continue;
    ans += dp(N-1,nextkind) % MODCONST;
    ans = ans % MODCONST;
  }
  return MEMO[N][kind]=ans;
}

int main(int argc, const char * argv[]) {

  ll N; cin >> N;
  MEMO = vector<vector<ll>>(N+1,vector<ll>(10,-1));
  for(ll i=1;i<=9;i++){
    MEMO[1][i] = 1;
  }
  // for(ll kind=1;kind<=9;kind++){
  //   dp(N,kind);
  // }

  for(ll i=2;i<=N;i++){
    for(ll kind=1;kind<=9;kind++){
      if(kind==1){
        MEMO[i][kind] = MEMO[i-1][kind]%MODCONST + MEMO[i-1][kind+1]%MODCONST;
        MEMO[i][kind] = MEMO[i][kind] % MODCONST;
      }
      else if(kind==9){
        MEMO[i][kind] = MEMO[i-1][kind-1]%MODCONST + MEMO[i-1][kind]%MODCONST;
        MEMO[i][kind] = MEMO[i][kind] % MODCONST;
      }
      else{
        MEMO[i][kind] = MEMO[i-1][kind-1]%MODCONST + MEMO[i-1][kind]%MODCONST + MEMO[i-1][kind+1]%MODCONST;
        MEMO[i][kind] = MEMO[i][kind] % MODCONST;
      }
    }
  }

  ll ans = 0;
  for(ll kind=1;kind<=9;kind++){
    ans += MEMO[N][kind] % MODCONST;
    ans = ans % MODCONST;
  }
  cout << ans << endl;

  return 0;
}