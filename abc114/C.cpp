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

ll value(vector<ll> A){
  ll ans=0;
  ll d=1;
  for(ll i=0;i<A.size();i++){
    ans += d*A[i];
    d*=10;
  }
  return ans;
}

ll ans=0;
ll N_digit;
ll N;

void dfs(vector<ll> A){
  if(value(A)>N){
    return;
  }

  bool flag3=false;
  bool flag5=false;
  bool flag7=false;
  for(ll i=0;i<A.size();i++){
    if(A[i]==3) flag3=true;
    if(A[i]==5) flag5=true;
    if(A[i]==7) flag7=true;
  }

  if(flag3 && flag5 && flag7) ans++;

  vector<ll> LIST={3,5,7};
  for(ll itr : LIST){
    A.push_back(itr);
    dfs(A);
    A.pop_back();
  }

  return ;
}

int main(int argc, const char * argv[]) {
  
  cin >> N;
  N_digit = log10(N)+1;
  vector<ll> A;
  dfs(A);

  cout << ans << endl;

  return 0;
}
