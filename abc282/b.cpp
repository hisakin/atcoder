#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
#define rep(i,n) for(ll i=0;i<n;i++)
int main(int argc, const char * argv[]) {

  ll N,M; cin >> N >> M;
  vector<string> S(N);

  for(ll i=0;i<N;i++){
    cin >> S[i];
  }

  ll ans=0;
  for(ll x=0;x<N;x++){
    for(ll y=x+1;y<N;y++){
      bool flag=true;
      for(ll i=0;i<M;i++){
        if(S[x][i]=='x' & S[y][i]=='x'){
          flag=false;
        }
      }
      if(flag) ans++;
    }
  }

  cout << ans << endl;
  return 0;
}