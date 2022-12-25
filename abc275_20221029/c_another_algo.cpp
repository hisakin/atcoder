#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll unsigned long long
using Graph = vector<vector<ll>>;

ll mypow(ll n){
  return n*n;
}

int main(int argc, const char * argv[]) {

  vector<string> S(9);
  for(ll i=0;i<9;i++){
    cin >> S[i];
  }
  vector<pair<ll,ll>> POS;
  for(ll i=0;i<9;i++){
    for(ll j=0;j<9;j++){
      if(S[i][j]=='#'){
        pair<ll,ll> pos = {i,j};
        POS.push_back(pos);
      }
    }
  }

  ll ans=0;
  for(ll a=0;a<POS.size();a++){
    for(ll b=a+1;b<POS.size();b++){
      for(ll c=b+1;c<POS.size();c++){
        for(ll d=c+1;d<POS.size();d++){
          vector<ll> v = {a,b,c,d};
          ll L6 = mypow(POS[v[0]].first - POS[v[2]].first) + mypow(POS[v[0]].second - POS[v[2]].second);
          ll L5 = mypow(POS[v[1]].first - POS[v[3]].first) + mypow(POS[v[1]].second - POS[v[3]].second);
          ll L1 = mypow(POS[v[0]].first - POS[v[1]].first) + mypow(POS[v[0]].second - POS[v[1]].second);
          ll L2 = mypow(POS[v[1]].first - POS[v[2]].first) + mypow(POS[v[1]].second - POS[v[2]].second);
          ll L3 = mypow(POS[v[2]].first - POS[v[3]].first) + mypow(POS[v[2]].second - POS[v[3]].second);
          ll L4 = mypow(POS[v[3]].first - POS[v[0]].first) + mypow(POS[v[3]].second - POS[v[0]].second);
          set<ll> SET;
          vector<ll> X = {L1,L2,L3,L4,L5,L6};
          sort(X.begin(),X.end());
          if((X[0]==X[1] && X[1]==X[2] && X[2]==X[3] && X[3]==X[0]) && X[4]==X[5]){
            ans++;
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}