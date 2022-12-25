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

int main(int argc, const char * argv[]) {
  ll N,K; cin >> N >> K;
  ll sum = 0;
  map<ll,ll> mp;
  for(ll i=K; i>0; i--){
    mp[i] = modpow(K/i,N);
    ll cnt=2;;
    while(i*cnt<=K){
      mp[i] = (mp[i] - mp[i*cnt]) % MOD;
      cnt++;
    }
    sum += i * mp[i];
  }

  cout << sum%MOD << endl;

  return 0;
}
