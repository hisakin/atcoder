#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;

vector<ll> ans;
vector<ll> seen;

void dfs(Graph &G, ll node){
  seen[node]=1;
  ans.push_back(node);
  for(auto next : G[node]){
    if(seen[next]==1) continue;
    dfs(G,next);
    ans.push_back(node);
  }
}

int main(int argc, const char * argv[]) {

  ll N; cin >> N;
  Graph G(N);
  seen = vector<ll>(N,-1);
  seen[0]=1;
  for(ll i=0;i<N-1;i++){
    ll a,b; cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  for(ll i=0;i<N;i++){
    sort(G[i].begin(),G[i].end());
  }

  dfs(G,0);
  for(ll i=0;i<ans.size();i++){
    cout << ans[i]+1 << " ";
  }

  return 0;
}