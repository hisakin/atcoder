#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;

ll N;
vector<ll> X,Y,P;


//深さ優先探索によるグラフ探索
vector<bool> seen;
void dfs(const Graph &G, ll v){
  seen[v] = true; //vを訪問済にする

  // vから行ける next_v について
  for(auto next_v : G[v]){
    if(seen[next_v]) continue; // next_vが探索済ならば探索しない
    dfs(G, next_v); //再帰的に探索
  }
}


//［2分探索用］
vector<ll> a = {1, 14, 32, 51, 51, 51, 243, 419, 750, 910};
// index が条件を満たすかどうか
bool isOK(ll mid_S) {

  //引数mid_sに従い、Pi*mid_S > |xj-xi| + |yj-yi| を満たす有向グラフを作成する
  Graph G(N);
  for (ll i=0;i<N;i++){
    for(ll j=0;j<N;j++){
      //座標i→jにジャンプできる場合
      if(P[i]*mid_S >= abs(X[j]-X[i]) + abs(Y[j]-Y[i]) ){
        G[i].push_back(j);
      }
    }
  }

  //Graph Gに対して。各頂点ごとに深さ優先探索をする。
  for(ll i=0;i<N;i++){
    seen.assign(N,false);
    dfs(G,i);
    //全ノードを探索できたかどうか判定
    bool isallsearched=true;
    for(ll j=0;j<N;j++){
      if(seen[j]==false){
        isallsearched=false;
        break;
      }
    }
    if(isallsearched) return true;
  }

  return false;

}
// 汎用的なめぐる式二分探索のテンプレ
ll binary_search() {
    ll ng = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
    ll ok = 4LL*1000000000LL + 1; // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;

        if (isOK(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}


int main(int argc, const char * argv[]) {

  cin >> N;
  X.assign(N,-1);
  Y.assign(N,-1);
  P.assign(N,-1);

  for(ll i=0;i<N;i++){
    cin >> X[i] >> Y[i] >> P[i];
  }

  ll S = binary_search();
  cout << S << endl;

}