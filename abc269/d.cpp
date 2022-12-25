#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long

//Union-Find
struct UnionFind {
  vector<ll> par, siz;

  //初期化
  UnionFind(ll n) : par(n,-1), siz(n,1){ }

  //根を求める
  ll root(ll x){
    if(par[x]==-1) return x;
    else return root(par[x]);
  }

  // xとyが同じグループに属するかどうか（根が一致するかどうか）
  bool issame(ll x, ll y){
    return root(x)==root(y);
  }

  // xを含むグループと yを含むグループを併合する
  bool unite(ll x, ll y){
    // x,yをそれぞれ根まで移動する
    x = root(x); y=root(y);

    //既に同じグループの時は何もしない
    if (x==y) return false;

    // union by size(y側のサイズが小さくなるようにする)
    if (siz[x] < siz[y]) swap(x,y);

    //yをxの子とする
    par[y]=x;
    siz[x]+=siz[y];
    return true;
  }

  //xを含むグループのサイズ
  ll size(ll x){
    return siz[root(x)];
  }

};

int main(int argc, const char * argv[]) {

  ll N; cin >> N;
  vector<ll> X(N),Y(N);
  for(ll i=0;i<N;i++){
    cin >> X[i] >> Y[i];
  }
  UnionFind uf(N);

  for(ll i=0;i<N;i++){
    for(ll j=i+1;j<N;j++){
      if      (X[j]==X[i]-1 && Y[j]==Y[i]-1) uf.unite(i,j);
      else if (X[j]==X[i]-1 && Y[j]==Y[i]  ) uf.unite(i,j);
      else if (X[j]==X[i]   && Y[j]==Y[i]-1) uf.unite(i,j);
      else if (X[j]==X[i]   && Y[j]==Y[i]+1) uf.unite(i,j);
      else if (X[j]==X[i]+1 && Y[j]==Y[i]  ) uf.unite(i,j);
      else if (X[j]==X[i]+1 && Y[j]==Y[i]+1) uf.unite(i,j);

    }
  }
  vector<bool> LIST(N,false); 
  ll ans=0;
  for(ll i=0;i<N;i++){
    if(uf.root(i)==i) ans++;
  }
  cout << ans << endl;
   return 0;

}

