#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;

int main(int argc, const char * argv[]) {

  ll N,Q; cin >> N >> Q;
  Graph G(N);
  for(ll i=0;i<N-1;i++){
    ll a,b; cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  vector<ll> color(N,-1);

  queue<ll> que;
  vector<ll> seen(N,-1);
  color[0]=0;
  ll cnt_color = 0;

  seen[0]=0;
  que.push(0);
  while(!que.empty()){
    ll current = que.front(); que.pop();
    for(ll next : G[current]){
      if(seen[next]!=-1) continue;
      seen[next] = seen[current] + 1;
      color[next] = seen[next] % 2;
      que.push(next);
    }
  }

  for(ll i=0;i<Q;i++){
    ll c,d; cin >> c >> d; c--; d--;;
    if(color[c]==color[d]){
      cout << "Town" << endl;
    }else{
      cout << "Road" << endl;
    }
  }

  return 0;
}