#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {

  ll N; cin >> N;
  ll const MODVAL = 998244353;
  vector<ll> A(N+1);
  for(ll i=1;i<=N;i++) cin >> A[i];

  vector<vector<ll>> MEMO(N+1,vector<ll>(10,0));
  MEMO[1][A[1]]++;

  for(ll i=1;i<N;i++){
    for(ll k=0;k<10;k++){
      if(MEMO[i][k]!=0){
        MEMO[i+1][(k+A[i+1])%10] += MEMO[i][k];
        MEMO[i+1][(k+A[i+1])%10] %= MODVAL;
        MEMO[i+1][(k*A[i+1])%10] += MEMO[i][k];
        MEMO[i+1][(k*A[i+1])%10] %= MODVAL;
      }
    }
  }

  for(ll k=0;k<10;k++){
    cout << MEMO[N][k] << endl;
  }

  return 0;
}