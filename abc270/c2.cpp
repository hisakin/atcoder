#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
ll Y;


void dfs(Graph &G,vector<ll> list, ll current, vector<bool> seen){

  cout << "current:" << current << endl;
  
  seen[current]=true;
  if(list.back()==Y){
    for(ll i=0;i<list.size();i++){
      cout << list[i]+1 <<" ";
    }
    return ;
  }

  for(ll x : G[current]){
    if(seen[x]) continue;
    list.push_back(x);
    dfs(G,list,x,seen);
    list.pop_back();
  }


}

int main(int argc, const char * argv[]) {

  ll N,X; cin >> N >> X >> Y;
  Graph G(N);
  X--; Y--;
  for(ll i=0;i<N-1;i++){
    ll u,v;
    cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  } 

  vector<bool> seen(N,false);
  // seen.resize(N);

  vector<ll> list;
  list.push_back(X);
  dfs(G,list,X,seen);

  return 0;
}