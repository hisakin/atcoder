#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {

  ll N, M; cin >> N >> M;
  vector<vector<ll>> X(M,vector<ll>());
  for(ll i=0;i<M;i++){
    ll k; cin >> k;
    for(ll j=0;j<k;j++){
      ll input; cin >> input; input--;
      X[i].push_back(input);
    }
  }

  // cout << endl;
  // for(ll i=0;i<M;i++){
  //   for(ll j=0;j<X[i].size();j++){
  //     cout << X[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  bool ans=true;
  for(ll i=0;i<N;i++){
    vector<ll> join(N,0);
    join[i]=1;
    for(ll j=0;j<M;j++){
      //iを含まない舞踏会はスキップ
      bool is_exist_i=false;
      for(ll q=0;q<X[j].size();q++){
        if(X[j][q]==i) is_exist_i=true;
      }
      if(!is_exist_i) continue;

      for(ll k=0;k<X[j].size();k++){
        join[X[j][k]]++;
      }
    }
    for(ll t=0;t<N;t++){
      if(join[t]==0) ans=false;
    }

    // cout << "i:" << i << " ";
    // for(ll t=0;t<N;t++){
    //   cout << join[t];
    // }
    // cout << endl;

  }

  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}