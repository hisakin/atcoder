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
  int N;cin >> N;
  vector<ll> P(N);
  for(int i=0;i<N;i++){
    cin >> P[i];
  }
  vector<ll> P_min(N);

  P_min[0] = P[0];
  for(int i=1;i<N;i++){
    P_min[i] = min(P_min[i-1], P[i]);
  }
  
  ll cnt = 0;
  for(int i=0;i<N;i++){
    if(P[i]<=P_min[i]) cnt++;
  }
  
  cout << cnt << endl;

   return 0;
}
