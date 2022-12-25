#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {

  ll H,W; cin >> H >> W;
  vector<vector<char>> C(H,vector<char>(W));
  for(ll i=0;i<H;i++){
    for (ll j=0;j<W;j++){
      cin >> C[i][j];
    }
  }

  for(ll j=0;j<W;j++){
    ll ans=0;
    for(ll i=0;i<H;i++){
      if(C[i][j]=='#') ans++;
    }
    cout << ans << " ";
  }




  return 0;
}