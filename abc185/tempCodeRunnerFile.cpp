#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {

  ll N,M; cin >> N >> M;
  vector<ll> A(M+2);
  for(ll i=1;i<=M;i++){
    cin >> A[i];
  }
  A[0]=0; A[M+1]=N+1;
  sort(A.begin(),A.end());



  ll k=2*N;
  // ll left=A[0];
  for(ll i=1;i<=M+1;i++){
    if(A[i]-A[i-1]-1==0) continue;
    k = min(k,A[i]-A[i-1]-1);
  }

  ll ans=0;
  for(ll i=1;i<=M+1;i++){
    ans+=((A[i]-A[i-1]-1) + (k-1))/k;
  }

  cout << ans << endl;

  return 0;
}