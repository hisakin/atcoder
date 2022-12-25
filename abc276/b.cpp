#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {

  ll N,M; cin >> N >> M;

  vector<vector<ll>> G(N);
  for(ll i=0;i<M;i++){
    ll a,b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  for(ll i=0;i<N;i++){
    sort(G[i].begin(),G[i].end());
  }

  for(ll i=0;i<N;i++){
    cout << G[i].size() << " ";
    if(G[i].size()==0){
      cout << endl;
      continue;
    }
    for(ll j=0;j<G[i].size();j++){
      cout << G[i][j]+1 << " ";
    }
    cout << endl;
  }

  return 0;
}