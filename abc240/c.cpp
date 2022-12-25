#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;


ll N,X;
vector<ll> A,B;
vector<vector<ll>> MEMO;

ll dp(ll n, ll x){
  if(x<0) return 0;
  if(MEMO[n][x]!=-1) return MEMO[n][x];

  ll temp_a,temp_b;
  temp_a = dp(n-1,x-A[n]);
  temp_b = dp(n-1,x-B[n]);

  if(temp_a==1 || temp_b == 1){
    return MEMO[n][x] = 1;
  }else{
    return MEMO[n][x] = 0;
  }
}

int main(int argc, const char * argv[]) {


  cin >> N >> X;
  A = vector<ll>(N+1);
  B = vector<ll>(N+1);

  for(ll i=1;i<=N;i++){
    cin >> A[i] >> B[i];
  }

  MEMO = vector<vector<ll>>(N+1,vector<ll>(X+1,-1));
  for(ll i=0;i<X+1;i++){
    MEMO[1][i] = 0;
  }
  MEMO[1][A[1]]=1;
  MEMO[1][B[1]]=1;

  dp(N,X);

  if(MEMO[N][X]==1){
    cout << "Yes" << endl;
  }else cout << "No" << endl;






  return 0;
}