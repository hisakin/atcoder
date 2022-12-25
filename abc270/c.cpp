#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;

vector<ll> BFS(ll s,Graph &G){
  ll N = (ll)G.size();
  vector<ll> dist(N,-1);
  queue<ll> que;

  dist[s]=0;
  que.push(s);

  while(!que.empty()){
    ll v = que.front();
    que.pop();

    for(ll x : G[v]){
      if(dist[x]!=-1) continue;

      dist[x]=dist[v]+1;
      que.push(x);
    }
  }

  return dist;
  
}

int main(int argc, const char * argv[]) {


  ll N,X,Y; cin >> N >> X >> Y;
  Graph G(N);
  X--; Y--;
  for(ll i=0;i<N-1;i++){
    ll u,v;
    cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  vector<ll> dist = BFS(X,G);

  ll current = Y;

  vector<ll> ans;
  while(true){
    ans.push_back(current);
    if(current==X) break;

    for(ll x : G[current]){
      if(dist[x]==dist[current]-1){
        current = x;
        break;
      }
    }
  }

  for(ll i=ans.size()-1;i>=0;i--){
    cout << ans[i]+1 << " ";
  }
  cout << endl;

  return 0;
}