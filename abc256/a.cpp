#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long

ll pow(ll x, ll n){
  if(n==0) return 1;
  return x*pow(x,n-1);
}


int main(int argc, const char * argv[]) {

  ll N; cin >> N;
  // ll x=2;

  cout << pow(2,N) << endl;




}