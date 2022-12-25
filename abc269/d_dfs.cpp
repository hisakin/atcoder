#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;

vector<bool> searched;
Graph G;


void dfs(ll i){

  searched[i]=true;

  for(auto s : G[i]){
    if(searched[s]) continue;
    dfs(s);
  }

}

int main(int argc, const char * argv[]) {

  ll N; cin >> N;
  vector<ll> X(N),Y(N);
  G = Graph(N);
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

  searched.assign(N,false);

  ll ans=0;
  for(ll i=0;i<N;i++){
    if(searched[i]) continue;
    ans++;
    dfs(i);
  }

cout << ans << endl;



  return 0;
}