#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;

int main(int argc, const char * argv[]) {

  ll N,M; cin >> N >> M;
  Graph G(N);
  for(ll i=0;i<M;i++){
    ll a,b; cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
    
  }
  ll ans = 0;
  for(ll a=0;a<N;a++){
    for(ll b=a+1;b<N;b++){
      for(ll c=b+1;c<N;c++){
        if(find(G[a].begin(),G[a].end(),b)!=G[a].end() && 
           find(G[b].begin(),G[b].end(),c)!=G[b].end() && 
           find(G[c].begin(),G[c].end(),a)!=G[c].end() ){
            ans++;
           }
      }
    }
  }
  cout << ans << endl;






  return 0;
}