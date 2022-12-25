#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {

 ll K; cin >> K;

 ll H = 21 + K/60;
 ll M = K%60;
 bool flag=false;
 if(M<10){
  flag=true;
 }

 if(flag){
 cout << H << ":" << "0" <<M << endl;
 }else{
   cout << H << ":" << M << endl;
 }


}