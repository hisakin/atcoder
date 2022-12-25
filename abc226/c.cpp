#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;


int main(int argc, const char * argv[]) {

  ll N; cin >> N;
  vector<ll> T(N);
  vector<ll> K(N);
  vector<vector<ll>> A(N);
  vector<bool> seen(N,false);
  Graph G(N);

  for(ll i=0;i<N;i++){
    cin >> T[i] >> K[i];
    for(ll k=0;k<K[i];k++){
      ll temp; cin >> temp; temp--;
      A[i].push_back(temp);
      G[i].push_back(temp);
    }
  }

  queue<ll> que;
  seen[N-1]=true;
  que.push(N-1);

  while(!que.empty()){
    ll node = que.front();
    que.pop();
    for(auto next : G[node]){
      if(seen[next]) continue;
      seen[next]=true;
      que.push(next);
    }
  }

  vector<ll> list;
  for(ll i=0;i<N;i++){
    if(seen[i]){
      list.push_back(i);
    }
  }

  ll ans=0;
  for(ll i=0;i<list.size();i++){
    ans += T[list[i]];
  }
  cout << ans << endl;
  return 0;
}