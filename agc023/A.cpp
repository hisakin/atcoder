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



int main(int argc, const char * argv[]) {
  ll N; cin >> N;
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
    ans+=MAP[(S[i])];
    MAP[(S[i])] += 1 ;
  }

  cout << ans << endl;

  return 0;
}
