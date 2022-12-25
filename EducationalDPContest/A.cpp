#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;

vector<ll> H;
ll N;

vector<ll> MEMO;

ll dp(ll n){
  if(MEMO[n]!=-1) return MEMO[n];
  return MEMO[n] = min(dp(n-1)+abs(H[n]-H[n-1]), dp(n-2)+abs(H[n]-H[n-2]));

}

int main(int argc, const char * argv[]) {

  cin >> N;
  H = vector<ll>(N+1);
  MEMO = vector<ll>(N+1,-1);
  H[0]=0;
  for(ll i=1;i<N+1;i++) cin >> H[i];

  MEMO[0]=0; MEMO[1]=0; MEMO[2]=abs(H[2]-H[1]);

  dp(N);

  cout << MEMO[N] << endl;

  return 0;
}