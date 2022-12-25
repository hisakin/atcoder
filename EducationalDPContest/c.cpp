#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;

vector<vector<ll>> HAPPY;
vector<vector<ll>> MEMO;

ll dp(ll n, ll kind){
  // cout << "n:" << n << "  kind:" << kind << endl;
  if(MEMO[n][kind]!=-1) return MEMO[n][kind];

  ll temp = 0;
  for(ll i=0;i<3;i++){
    if(kind==i) continue;
    temp = max(temp,dp(n-1,i)+HAPPY[n][kind]);
  }
  return MEMO[n][kind] = temp;

}

int main(int argc, const char * argv[]) {

  ll N; cin >> N;
  HAPPY = vector<vector<ll>>(N+1,vector<ll>(3));
  HAPPY[0][0]=0;
  HAPPY[0][1]=0;
  HAPPY[0][2]=0;
  for(ll i=1;i<=N;i++){
    cin >> HAPPY[i][0] >> HAPPY[i][1] >> HAPPY[i][2];
  }
  MEMO = vector<vector<ll>>(N+1,vector<ll>(3,-1));
  MEMO[1][0]=HAPPY[1][0];
  MEMO[1][1]=HAPPY[1][1];
  MEMO[1][2]=HAPPY[1][2];
  MEMO[0][0]=0;
  MEMO[0][1]=0;
  MEMO[0][2]=0;

  dp(N,0);
  dp(N,1);
  dp(N,2);

  ll ans=0;
  for(ll i=0;i<3;i++){
    ans = max(MEMO[N][i],ans);
  }
  cout << ans << endl;

  // for(ll i=0;i<=N;i++){
  //   for(ll j=0;j<3;j++){
  //     cout << "MEMO[" << i << "][" << j << "]:" << MEMO[i][j] << " ";
  //   }
  //   cout << endl;
  // }



  return 0;
}