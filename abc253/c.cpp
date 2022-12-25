#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
#define rep(i,n) for(ll i=0;i<n;i++)
int main(int argc, const char * argv[]) {

  ll Q; cin >> Q;
  vector<vector<ll>> query(Q);
  for(ll i=0;i<Q;i++){
    ll q1,q2,q3; cin >> q1; query[i].push_back(q1);
    if(q1==1){
      cin >> q2;
      query[i].push_back(q2);

    }else if(q1==2){
      cin >> q2 >> q3;
      query[i].push_back(q2);
      query[i].push_back(q3);
    }
  }


  map<ll,ll> MAP;
  for(ll i=0;i<Q;i++){
    if(query[i][0]==1){
      MAP[query[i][1]]++;
    }
    else if(query[i][0]==2){
      // MAP[query[i][1]-'0'] -= min(MAP[query[i][1]-'0'],query[i][2]-'0');
      MAP[query[i][1]] -= query[i][2];
      if(MAP[query[i][1]] <= 0) MAP.erase(query[i][1]);
    }
    else{
      ll dist = MAP.rbegin()->first - MAP.begin()->first;
      cout << dist << endl;
    }
  }
  
  return 0;
}