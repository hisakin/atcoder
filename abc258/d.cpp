#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long

ll pow(ll x, ll n){
  if(n==0) return 1;
  return x * pow(x,n-1);
}

int main(int argc, const char * argv[]) {


  ll N, X; cin >> N >> X;
  vector<ll> A(N),B(N),SUM(N+1,0);
  for(ll i=0;i<N;i++){
    cin >> A[i] >> B[i];
    SUM[i+1] =  SUM[i] + A[i] + B[i];
  }

  ll ans=4*pow(10,18);
  ll new_N = N;
  if(X<N){
    new_N = X;
  }
  for(ll i=0;i<new_N;i++){
    ll temp = SUM[i+1] + (X - i - 1)* B[i];
    ans = min(ans,temp);
  }

  cout << ans << endl;

}