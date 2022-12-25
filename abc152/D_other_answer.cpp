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

P calc_head_tail(ll x){
  int head,tail;
  head = x%10;
  while(x){
    tail=x;
    x/=10;
  }
  P p;
  p.first= head; p.second=tail;
  return p;
}

int main(int argc, const char * argv[]) {
  ll N; cin >> N;
  map<P,ll> MAP;
  for(ll i=1;i<=N;i++){
    MAP[calc_head_tail(i)]++;
  }

  ll ans=0;
  for(int i=1;i<=N;i++){
    P p = calc_head_tail(i);
    P q(p.second,p.first);
    ans += MAP[q];
  }
  cout << ans << endl;
  return 0;
}
