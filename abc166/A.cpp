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
    cout <<"   dsfaf" << endl;
   ll N; cin>> N;

   vector<ll> A(N);
   rep(i,N) cin >> A[i];

   ll ans=0;

   map<ll,ll> L;
   map<ll,ll> R;
   rep(i,N){
//        L[i+A[i]]++;
       R[i-A[i]]++;
   }
   rep(i,N){
       ans += R[i+A[i]];
   }

   cout << ans << endl;


//    賢い人の回答
//    ll r = 0;
//     map<ll,ll> cnt;
//     for(ll i=0; i<n; i++) {
//         r += cnt[i-a[i]];
//         cnt[a[i]+i]++;
//     }
//     cout <<r << endl;


   return 0;
}
