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

int ctoi(const char c){
 switch(c){
   case '0': return 0;
   case '1': return 1;
   case '2': return 2;
   case '3': return 3;
   case '4': return 4;
   case '5': return 5;
   case '6': return 6;
   case '7': return 7;
   case '8': return 8;
   case '9': return 9;
   default : return -1;
 }
}

long long modpow(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

int main(int argc, const char * argv[]) {
  ll N; cin >> N ;
  vector< bitset<61> > A;

  for(ll i=0;i<N;i++){
    ll temp; cin >> temp;
    bitset<61> B(temp);
    A.push_back(B);    
  }

  ll ans = 0;
  for(ll i=0; i<61; i++){
    ll one_num = 0;
    for(ll j=0; j<N;j++){
      if(A[j][i]) one_num++;
    }
    ans = ( ans + ((one_num * (N - one_num)) % MOD ) * modpow(2,i) ) % MOD;
  }

  cout << ans % MOD << endl;

  return 0;
}
