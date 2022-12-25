#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {


  ll N; cin >> N;
  vector<ll> A(N);
  vector<ll> B(N);

  for(ll i=0;i<N;i++){
    cin >> A[i] >> B[i];
  }

  ll ans=0;
  for(ll i=0;i<N;i++){
    ans += ((A[i]+B[i])*(B[i]-A[i]+1))/2;
  }

  cout << ans << endl;




}