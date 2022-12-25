#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;

struct kabeX{
  ll X;
  ll Y;
  // 最後のconstを忘れると"instantiated from here"というエラーが出てコンパイルできないので注意
  bool operator<( const kabeX& right ) const {
    return num == right.num ? Y < right.Y : X < right.X;
}

};
struct kabeY{
  ll X;
  ll Y;
  // 最後のconstを忘れると"instantiated from here"というエラーが出てコンパイルできないので注意
  bool operator<( const kabeY& right ) const {
    return Y == right.Y ? X < right.X : Y < right.Y;
};

int main(int argc, const char * argv[]) {

  ll H,W; cin >> H >> W;
  ll xs,ys; cin >> xs >> ys;
  ll N; cin >> N;
  vector<kabeX> KABELIST_X(N);
  vector<kabeY> KABELIST_Y(N);
  for(ll i=0;i<N;i++){
    cin >> KABELIST_X[i].X >> KABELIST_X[i].Y;
    KABELIST_Y[i].X = KABELIST_X[i].X;
    KABELIST_Y[i].Y = KABELIST_X[i].Y;
  }

  ll Q; cin >> Q;
  vector<ll> D(Q),L(Q);
  for(ll i=0;i<Q;i++){
    cin >> D[i] >> L[i];
  }

  sort(KABELIST_X.begin(),KABELIST_X.end());
  sort(KABELIST_Y.begin(),KABELIST_Y.end());

  for(ll i=0;i<Q;i++){
    
  }






  return 0;
}