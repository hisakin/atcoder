#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long

struct Cycle {
  ll x,y,r;
};

ll pow(ll x){
  return x*x;
}

//Union-Find
struct UnionFind {
  vector<ll> parent, size;

  UnionFind(ll n) : parent(n,-1) , size(n, 1) { }

  //根を求める
  ll root (ll x){
    if(parent[x]==-1) return x;
    else return parent[x] = root(parent[x]); //経路圧縮(xから根までの親を根の子へ張り替える)
  }

  // xとyが同じグループに属するのかどうか (根が一致するのかどうか)
  bool issame(ll x, ll y) {
    return root(x) == root(y);
  }

  // xを含むグループと yを含むグループを併合する
  bool unite(ll x, ll y){
    // x, yをそれぞれ根まで移動させる
    x = root(x); y = root(y);

    // 既に同じグループの時は何もしない
    if (x == y) return false;

    // union by size (y側のサイズが小さくなるようにする)
    if (size[x] < size[y]) swap(x, y);

    // y を xの子とする
    parent[y] = x;
    size[x] += size[y];
    return true;
  }
};

bool iscyclecrossed( Cycle Ci, Cycle Cj){
  if( pow(Ci.r - Cj.r) <= pow(Ci.x - Cj.x) + pow(Ci.y - Cj.y) &&
      pow(Ci.r + Cj.r) >= pow(Ci.x - Cj.x) + pow(Ci.y - Cj.y)) {
        return true;
  }else{
    return false;
  }
}

bool ispointoncycle(ll sx, ll sy, Cycle Ci){
  if ( pow(sx - Ci.x) + pow(sy - Ci.y) == pow(Ci.r) ){
    return true;
  }else{
    return false;
  }
}


int main(int argc, const char * argv[]) {

  ll N, sx, sy, tx, ty; cin >> N >> sx >> sy >> tx >> ty;
  vector<Cycle> C(N);
  UnionFind uf(N);
  for(ll i=0;i<N;i++){
    cin >> C[i].x >> C[i].y >> C[i].r;
  }

  // 各円同士が交わるかどうかを判定。交わる場合はunionfindによりグルーピングを実施。
  for(ll i=0; i<N; i++){
    for (ll j=i+1; j<N; j++){
      if(iscyclecrossed(C[i], C[j])) uf.unite(i,j);
      else { continue; }
    }
  }

  ll ans=0;
  for(ll i=0;i<N; i++){
    if(!ispointoncycle(sx,sy,C[i])) continue;
    for(ll j=0; j<N;j++){
      if(!ispointoncycle(tx,ty,C[j])) continue;
      if(uf.issame(i,j)) ans++;
    }
  }

  if(ans>0){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }

}