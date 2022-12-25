#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;

ll N,K;
vector<ll> H;
vector<ll> MEMO;

ll dp(ll n){
  if(MEMO[n]!=-1) return MEMO[n];

  ll temp_min = 1000000000+1;
  for(ll i=1;i<=K;i++){
    if(n-i<=0) continue;
    temp_min = min(temp_min,dp(n-i)+abs(H[n]-H[n-i]));
  }
  return MEMO[n]=temp_min;

}

int main(int argc, const char * argv[]) {

  cin >> N >> K;
  H = vector<ll>(N+1);
  MEMO = vector<ll>(N+1,-1);
  for(ll i=1;i<=N;i++) cin >> H[i];
  H[0]=0;

  MEMO[0]=0; MEMO[1]=0;
  dp(N);

  cout << MEMO[N] << endl;





  return 0;
}