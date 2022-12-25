#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bitset>
typedef long long ll;
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef pair<int,int> P;

const int MOD = 1000000007;

ll gcd(ll x, ll y){
  if(x%y==0){
    return y;
  }
  else{
    return gcd(y,x%y);
  }

}

ll lcm(ll x, ll y){
  return (x*y)/gcd(x,y);
}

int main(int argc, const char * argv[]) {
  ll N; cin >> N;
  vector<ll> A(N);
  rep(i,N) cin >> A[i];
  ll lcm_all=1;

  rep(i,N){
    lcm_all = lcm(lcm_all,A[i]);
  }

  ll sum=0;
  rep(i,N){
    sum = (sum + (lcm_all / A[i]) )% MOD;
  }
  cout << sum%MOD << endl;
}
