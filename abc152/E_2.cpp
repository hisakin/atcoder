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

Bint gcd(Bint x, Bint y){
  if(x%y==0){
    return y;
  }
  else{
    return gcd(y,x%y);
  }

}

Bint lcm(Bint x, Bint y){
  return (x*y)/gcd(x,y);
}

int main(int argc, const char * argv[]) {
  ll N; cin >> N;
  vector<ll> A(N);
  rep(i,N) cin >> A[i];
  Bint lcm_all=1;

  rep(i,N){
    lcm_all = lcm(lcm_all,A[i]);
  }

  Bint sum=0;
  rep(i,N){
    sum = (sum + (lcm_all / A[i]) )% MOD;
  }
  cout << sum%MOD << endl;
}
