#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {

  ll Q; cin >> Q;
  vector<vector<ll>> query(Q);
  for(ll i=0;i<Q;i++){
    ll kind; cin >> kind;
    query[i].push_back(kind);
    if(kind==1){
      for(ll j=0;j<2;j++){
        ll input; cin >> input;
        query[i].push_back(input);
      }
    }
    else{
      ll input; cin >> input;
      query[i].push_back(input);
    }
  }

  vector<ll> KIND;
  vector<ll> NUM;

  ll cnt=0;
  for(ll i=0;i<Q;i++){
    if(query[i][0]==2) continue;
    KIND.push_back(query[i][1]);
    NUM.push_back(query[i][2]);
  }

  for(ll i=0;i<Q;i++){
    if(query[i][0]==1) continue;
    
    ll ans = SUM[query[i][1]+index]-SUM[index];
    cout << ans << endl;
    index += query[i][1];
  }





  return 0;
}