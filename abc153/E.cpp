#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bitset>

#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
// 任意長整数型
using Bint = mp::cpp_int;
// 仮数部が1024ビットの浮動小数点数型(TLEしたら小さくする)
using Real = mp::number<mp::cpp_dec_float<1024>>;

typedef long long ll;
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef pair<int,int> P;

const int MOD = 1000000007;





int main(int argc, const char * argv[]) {
  ll H,N; cin >> H >> N;
  vector<ll> a(N+1);
  vector<ll> b(N+1);
  ll max_a=0, max_b=0;
  for(ll i=1;i<=N;i++){
    cin >> a[i] >> b[i];
    max_a = max(max_a,a[i]);
    max_b = max(max_b,b[i]);

  } 

  // cout << max_a << "  " << max_b << endl;
  ll dp[N+1][H+max_a+1];
  for(ll i=0;i<N+1;i++){
    for(ll j=0;j<H+max_a+1;j++){
      dp[i][j]= H*max_b;
      // cout << dp[i][j] << " " << endl;
    }
    // cout << endl;
  }
  for(ll i=1;i<N+1;i++){
    for(ll j=1;j<H+max_a+1;j++){
      if(j-a[i]<0) dp[i][j] = dp[i-1][j];
      else if(a[i]==j){
        dp[i][j] = min(dp[i-1][j],b[i]);
      }else{
        dp[i][j] = min(dp[i-1][j],dp[i][j-a[i]]+b[i]);
      }
    }
  }

  ll ans = H*max_b;
  for(ll i=H;i<=H+max_a;i++){
    ans = min(ans,dp[N][i]);
  }

  cout << ans << endl;


}
