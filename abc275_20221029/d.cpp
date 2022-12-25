#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;

map<ll,ll> MAP;

ll dfs(ll n){
  if(MAP[n]!=0) return MAP[n];
  ll ret1 = dfs(n/2);
  ll ret2 = dfs(n/3);
  MAP[n] = ret1 + ret2;
  return MAP[n];
}

int main(int argc, const char * argv[]) {

  ll N; cin >> N;
  MAP[0]=1;
  ll ans = dfs(N);
  cout << ans << endl;
  return 0;
}