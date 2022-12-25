#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;

vector<vector<ll>> pass;
void dfs(Graph graph, vector<ll> p, ll N){
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
      dfs(graph,p,N);
      p.pop_back();
    }
  }
}

int main(int argc, const char * argv[]) {

  ll N, M; cin >> N >> M;
  vector<ll> a(M),b(M);
  for(ll i=0;i<M;i++){
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
  }
  cout << "hello" << endl;

  Graph graph(N);

  cout << "graph[" << 0 << "]のアドレス：" << &graph[0] << endl;
  cout << "graph[" << 1 << "]のアドレス：" << &graph[1] << endl;
  cout << "graph[" << 2 << "]のアドレス：" << &graph[2] << endl;
  cout << "graph[" << 3 << "]のアドレス：" << &graph[3] << endl;
  cout << "graph[" << 4 << "]のアドレス：" << &graph[4] << endl;


  cout << "graphのアドレス：" << &graph << endl;
  for(ll i=0;i<M;i++){
      graph[a[i]].push_back(b[i]);
      cout << "graph[" << a[i] << "]のアドレス：" << &graph[a[i]] << endl;
      graph[b[i]].push_back(a[i]);
      cout << "graph[" << b[i] << "]のアドレス：" << &graph[b[i]] << endl;
  }
  // return 0;


  vector<ll> hoge;
  hoge.push_back(0);
  // cout << "[" << i << "] : " << endl;
  dfs(graph,hoge,N);
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