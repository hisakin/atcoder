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

ll N,M;
vector<ll> A;
ll check(ll X){
    ll sum = 0;
  for(ll i=0;i<N;i++){
    // A[j]=X-A[i]以上の個数をカウント：O(logN)
    sum  +=  N - (lower_bound(A.begin(),A.end(),X-A[i]) - A.begin());
  }
  return sum;
}

int main(int argc, const char * argv[]) {
  cin >> N >> M;
  A = vector<ll>(N);
  for(ll i=0;i<N;i++) cin >> A[i];
  sort(A.begin(),A.end());

  ll ng = -1, ok = A[N-1]*2;

  while(abs(ok-ng)>1){
    ll mid = (ng+ok)/2;
    if(check(mid)<M) ok = mid;
    else{ ng = mid; }
  }

  vector<ll> S(N+1);
  for(ll i=0;i<N;i++) S[i+1]=S[i]+A[i];

  ll ans=0;
  ll cnt=0;
  for(ll i=0;i<N;i++){
    // X - A[i] 以下の個数を求める
    ll pos = upper_bound(A.begin(),A.end(),ok-A[i]) - A.begin();
    // X - A[i] を超える値の個数を求める
    cnt = N - pos;
    // 数をカウント
    ans += cnt*A[i] + S[N]-S[pos];
    M -= cnt;
  }

  ans += M * ok;

  cout << ans << endl;
  return 0;
}
