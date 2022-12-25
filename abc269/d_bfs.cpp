#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {

  ll N; cin >> N;
  vector<ll> X(N),Y(N);
  Graph G(N);
  for(ll i=0;i<N;i++){
    cin >> X[i] >> Y[i];
  }

  for(ll i=0;i<N;i++){
    for(ll j=i+1;j<N;j++){
      if      (X[j]==X[i]-1 && Y[j]==Y[i]-1) {G[i].push_back(j); G[j].push_back(i); }
      else if (X[j]==X[i]-1 && Y[j]==Y[i]  ) {G[i].push_back(j); G[j].push_back(i); }
      else if (X[j]==X[i]   && Y[j]==Y[i]-1) {G[i].push_back(j); G[j].push_back(i); }
      else if (X[j]==X[i]   && Y[j]==Y[i]+1) {G[i].push_back(j); G[j].push_back(i); }
      else if (X[j]==X[i]+1 && Y[j]==Y[i]  ) {G[i].push_back(j); G[j].push_back(i); }
      else if (X[j]==X[i]+1 && Y[j]==Y[i]+1) {G[i].push_back(j); G[j].push_back(i); }
    }
  }

  vector<bool> searched(N,false);

  ll ans=0;
  for(ll i=0;i<N;i++){
    if(searched[i]) continue;
    searched[i]=true;
    
    queue<ll> q;
    q.push(i);
    while(!q.empty()){
      ll current = q.front(); q.pop();
      for(auto next : G[current]){
        if(searched[next]) continue;
        searched[next]=true;
        q.push(next);
      }
    }
    ans++;
  }

  cout << ans << endl;

  return 0;
}