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

ll value(int a,int b){
  ll d=10;
  ll sum=0;
  for(int i=0;i<b;i++){
  //  cout << sum << endl;
    sum = d*sum + a;
  }
  return sum;
}

int main(int argc, const char * argv[]) {
  int a,b;cin >> a >> b;
  ll a_sum = value(a,b);
  ll b_sum = value(b,a);
  cout << max(a_sum,b_sum) << endl;

   return 0;
}
