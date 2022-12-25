#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bitset>
typedef long long ll;
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

const int MAX = 510000;
const int MOD = 1000000007;
const int MAX_N = 200000;

ll X,Y;

bool check_i_2_j_1(ll i, ll j){
  if(i-2<0 || j-1<0) return false;
  return true;
}
bool check_i_1_j_2(ll i, ll j){
  if(i-1<0 || j-2<0) return false;
  return true;
}

ll dfs(ll i, ll j){
  if(i>X )
}

int main(int argc, const char * argv[]) {

  cin >> X >> Y;

  vector<vector<ll>> dp;
  for(ll i=0;i<=X;i++){
    for(ll j=0;j<=Y;j++){
      dp[i].push_back(0);
    }
  }

  dp[0][0] = 1;
  for(ll i=0;i<=X;i++){
    for(ll j=0;j<=Y;j++){
      if(!check_i_1_j_2(i,j) && !check_i_2_j_1(i,j))
        dp[i][j]=0;
      else if(check_i_1_j_2(i,j) && check_i_2_j_1(i,j)){
        dp[i][j] = dp[i-2][j-1] + dp[i-1][j-2];
        dp[i][j] %= MOD;
      }
      else if(check_i_1_j_2(i,j)){
        dp[i][j] = dp[i-1][j-2];
      }
      else{
        dp[i][j] = dp[i-2][j-1];
      }
    }
  }
  
  cout << dp[X][Y] << endl;

   return 0;  
}
