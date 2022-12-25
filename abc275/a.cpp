#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {

  ll N; cin >> N;
  ll ans=1;
  for(ll i=1;i<=N;i++){
    ans = ans*i;
  }

  cout << ans << endl;

  return 0;
}