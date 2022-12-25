#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {

  ll N; cin >> N;
  vector<ll> A(N);
  ll i;

  for(i=0;i<N;i++){
    cin >> A.at(i);
  }

  ll sum=0;
  for(i=0;i<N;i++){
    sum = sum + A.at(i);
    sum = sum % mod;
  }
  ll ans=0;
  for(i=0;i<N-1;i++){
    sum = sum - A.at(i);
    sum = sum % mod;
    ans = ans + (A.at(i)*sum)%mod;
    ans = ans % mod;
  }

  ans = (ans + mod)%mod;

  cout << ans << endl;

}