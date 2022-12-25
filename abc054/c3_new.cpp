#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
Graph graph;

vector<vector<ll>> pass;
void dfs(vector<ll> p, ll N){
  if(p.size()==N){
    pass.push_back(p);
    return;
  }
  for(ll i=0;i<N;i++){
    bool flag=false;
    for(ll j=0;j<p.size();j++){
      if(p[j]==i){
        flag=true;
        break;
      }
    }
    if(!flag){
      p.push_back(i);
      dfs(p,N);
      p.pop_back();
    }
  }
}

int main(int argc, const char * argv[]) {

  ll N, M; cin >> N >> M;
  ll a,b;
  graph.resize(N);
  for(ll i=0;i<M;i++){
    cin >> a >> b; a--; b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  vector<ll> hoge;
  hoge.push_back(0);
  dfs(hoge,N);
  ll ans=0;

  for(ll i=0;i<pass.size();i++){
    bool flag=true;
    for(ll j=0;j<pass[i].size()-1;j++){
      ll current_node = pass[i][j];
      ll next_node = pass[i][j+1];
      bool ispass=false;
       for(ll k=0;k<graph[current_node].size();k++){
        if(graph[current_node][k]==next_node){
          ispass=true;
        }
      }
      if(!ispass){
        flag=false;
      }
    }
    if(flag){
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}