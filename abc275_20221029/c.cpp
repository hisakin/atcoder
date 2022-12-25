#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
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

  if(POS.size()<=3){
    cout << 0 << endl;
    return 0;
  }
  ll ans=0;
  for(ll a=0;a<POS.size();a++){
    for(ll b=0;b<POS.size();b++){
      for(ll c=0;c<POS.size();c++){
        for(ll d=0;d<POS.size();d++){
          if(a==b||a==c||a==d||b==c||b==d||c==d) continue;
          bool check_taikaku=false;
          ll L6 = mypow(POS[a].first - POS[c].first) + mypow(POS[a].second - POS[c].second);
          ll L5 = mypow(POS[b].first - POS[d].first) + mypow(POS[b].second - POS[d].second);
          if(L5 == L6) check_taikaku=true;

          ll L1 = mypow(POS[a].first - POS[b].first) + mypow(POS[a].second - POS[b].second);
          ll L2 = mypow(POS[b].first - POS[c].first) + mypow(POS[b].second - POS[c].second);
          ll L3 = mypow(POS[c].first - POS[d].first) + mypow(POS[c].second - POS[d].second);
          ll L4 = mypow(POS[d].first - POS[a].first) + mypow(POS[d].second - POS[a].second);
          bool check_4len = false;
          if(L1==L2 && L2==L3 && L3==L4 && L4 == L1) check_4len=true;

          bool check_grad1=false;
          if((POS[b].first-POS[a].first)*(POS[c].first-POS[b].first) + 
             (POS[b].second-POS[a].second)*(POS[c].second-POS[b].second) == 0){
              check_grad1 = true;
          }

          bool check_grad2=false;
          if((POS[d].first-POS[a].first)*(POS[c].first-POS[d].first) + 
             (POS[d].second-POS[a].second)*(POS[c].second-POS[d].second) == 0){
              check_grad2 = true;
          }

          if(check_4len && check_taikaku && check_grad1 && check_grad2){
            ans++;
            cout << "a:" << a << " b:" << b << " c:" << c << " d:" << d << endl;
            cout << "(" << POS[a].first << "," << POS[a].second << ")" << endl;
            cout << "(" << POS[b].first << "," << POS[b].second << ")" << endl;
            cout << "(" << POS[c].first << "," << POS[c].second << ")" << endl;
            cout << "(" << POS[d].first << "," << POS[d].second << ")" << endl;
          }
        }


      }
    }
  }
  cout << ans << endl;
  return 0;
}