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
   double a,b,x;cin >> a >> b>>x;
   double ans;
   if((a*a*b)/2.0<x){
     ans = atan((2*a*a*b-2*x)/(a*a*a)) * 180 / M_PI;
   }else{
     ans = atan((a*b*b)/(2*x)) * 180 / M_PI;
   }

   cout <<fixed << setprecision(10)<< ans << endl;


   return 0;  
}
