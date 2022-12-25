#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;

struct pos{
    ll x;
    ll y;
    char direction;

    // 最後のconstを忘れると"instantiated from here"というエラーが出てコンパイルできないので注意
    bool operator<( const pos& right ) const {
        return y < right.y ;
    }
};

int main(int argc, const char * argv[]) {

  ll N;  cin >> N;
  vector<pos> POS(N);
  for(ll i=0;i<N;i++){
    ll x; cin >> x;
    ll y; cin >> y;
    POS[i].x = x;
    POS[i].y = y;
  }

  for(ll i=0;i<N;i++){
    char c; cin >> c;
    POS[i].direction = c;
  }

  sort(POS.begin(),POS.end());
  map<ll,ll> MAP_R;
  map<ll,ll> MAP_L;

  // for(ll i=0;i<N;i++){
  //   cout << "x:" << POS[i].x << "  y:" << POS[i].y << "  diretion:" << POS[i].direction << endl;
  // }
  // cout << endl;

  for(ll i=0;i<N;i++){
    if(POS[i].direction=='L'){
      // cout << "L" << endl;
      if(MAP_L.find(POS[i].y)==MAP_L.end()){
        MAP_L[POS[i].y] = POS[i].x;
      }
      else{
        MAP_L[POS[i].y] = max(POS[i].x, MAP_L[POS[i].y]);//更新
      }
    }else{
      // cout << "R" << endl;
      if(MAP_R.find(POS[i].y)==MAP_R.end()){
        MAP_R[POS[i].y] = POS[i].x;
      }
      else{
        MAP_R[POS[i].y] = min(POS[i].x, MAP_R[POS[i].y]);//更新
      }
    }
  }

  // for(ll i=0;i<N;i++){
  //   cout << "key:" << POS[i].y << "  MAP_L:" << MAP_L[POS[i].y] << "  MAP_R:" << MAP_R[POS[i].y] << endl;
  // }

  ll ans=false;
  for(ll i=0;i<N;i++){
    if(MAP_L.find(POS[i].y)==MAP_L.end() || MAP_R.find(POS[i].y)==MAP_R.end()) continue;
    if(MAP_R[POS[i].y]<MAP_L[POS[i].y]) ans=true;
  }

  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}