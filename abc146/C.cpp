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
ll A,B,X;

bool solve(ll mid){

  if(X < A * mid) return false;
  if(X >= A*mid +B*((ll)log10(mid)+1)) return true;
  return false;
}

int main(int argc, const char * argv[]) {
  cin >> A >> B >> X;
  ll ok = 0;
  ll ng = pow(10,9)+1;



  while(abs(ng-ok)>1){
    ll mid = (ok+ng)/2;
    if(solve(mid)) ok = mid;
    else{
      ng = mid;
    }
  }

  cout << ok << endl;

  return 0;
}
