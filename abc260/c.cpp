#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;

ll N,X,Y;
vector<vector<ll>> memo;
ll F(ll kind, ll n){


  if(memo[kind][n]!=-1) return memo[kind][n];
  if(kind==0 && n==1) return 0;
  if(kind==1 && n==1) return 1;

  ll ret;
  if(kind==0){
    memo[kind][n] = F(0,n-1) + X*F(1,n);
  }else{
    memo[kind][n] = F(0,n-1) + Y*F(1,n-1);
  }
  return memo[kind][n];
}


int main(int argc, const char * argv[]) {

  cin >> N >> X >> Y;
  memo = vector<vector<ll>>(2);
  for(ll i=0;i<2;i++){
    for(ll j=0;j<N+1;j++){
      memo[i].push_back(-1);
    }
  }

  memo[0][1]=0;
  memo[1][1]=1;
  ll ans = F(0,N);
  cout << ans << endl;


  // cout << "memo" << endl;
  // for(ll i=0;i<2;i++){
  //   for(ll j=0;j<N+1;j++){
  //     cout << memo[i][j] << "  ";
  //   }
  //   cout << endl;
  // }

  






  return 0;
}