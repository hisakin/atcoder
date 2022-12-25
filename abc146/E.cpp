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

int main(int argc, const char * argv[]) {
  ll N,K; cin >> N >> K;
  ll ans=0;
  vector<ll> A(N);
  for(ll i=0;i<N;i++){
    cin >> A[i];
  }
  vector<ll> S(N+1);
  S[0]=0;
  for(ll i=0;i<N;i++){
    S[i+1]=S[i]+A[i];
  }

  map<ll,ll> MAP;
  for(ll i=0;i<=N;i++){
    ans+=MAP[(S[i]-i)%K];
    MAP[(S[i]-i)%K] += 1 ;
    if(i>=K-1){
      MAP[(S[i-K+1]-(i-K+1))%K] -= 1 ;
    }
  }

  // for(auto x : MAP){
  //   cout << "key : " << x.first << "  value : " << x.second << endl;
  // }

  cout << ans << endl;

  return 0;
}
