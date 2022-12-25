#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {

  ll N,M; cin >> N >> M;
  ll const modC = 1000000007;
  Graph G(N);
  for(ll i=0;i<M;i++){
    ll a,b; cin >> a >>b; a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  vector<ll> seen(N,-1);
  seen[0]=0;
  queue<ll> que;
  que.push(0);
  vector<ll> cnt(N,0);
  cnt[0]=1;
  
  while(!que.empty()){
    ll current = que.front();
    que.pop();
    for(auto next : G[current]){
      if(seen[next]==-1){
        seen[next] = seen[current] + 1;
        cnt[next] = cnt[current];
        que.push(next);
      }else if(seen[next]!=-1){
        if(seen[current]+1 == seen[next]){
          cnt[next] += cnt[current];
          cnt[next]%= modC;
        }
      }
    }
  }

  if(seen[N-1]==-1){
    cout << 0 << endl;
  }else{
    cout << cnt[N-1] << endl;
  }
  return 0;
}