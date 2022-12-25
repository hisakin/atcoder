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

ll modpow(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

ll mod_factrial_up(ll start, ll end){
  ll sum=1;
  for(ll i=start;i>=end; i--){
    sum = (sum * i) % MOD;
  }
  return sum;
}

// mod_factrial(N,k+1): nCkの分母：(n-k)^p-2 * (n-k-1)^p-2 * ... * 1^p-2 を計算
ll mod_factrial_down(ll start, ll end){
  ll sum=1;
  for(ll i=start; i>=end;i--){
    sum = (sum * i) % MOD;
    // sum = (sum * modpow(i,MOD-2) ) % MOD;
  }
  sum = modpow(sum,MOD-2);
  return sum;
}


int main(int argc, const char * argv[]) {
  ll N,a,b; cin >> N >> a >> b;
  ll sum = (modpow(2,N)-1 - (mod_factrial_up(N,N-a+1) * mod_factrial_down(a,1))%MOD - (mod_factrial_up(N,N-b+1) * mod_factrial_down(b,1))%MOD ) %MOD;
  if (sum<0) sum += MOD;
   cout << sum << endl;
  //  cout << -1 % MOD << endl;
}
