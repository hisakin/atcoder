#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;

vector<pair<ll,ll>> POS;
// index が条件を満たすかどうか
bool isOK(ll index, pair<ll,ll> key) {
    if (POS[index].first > key.first) return true;
    if ((POS[index].first == key.first) && (POS[index].second >= key.second) ) return true;
    else return false;
}
// 汎用的な二分探索のテンプレ
int binary_search(pair<ll,ll> key) {
    ll ng = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
    ll ok = (ll)POS.size(); // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;

        if (isOK(mid, key)) ok = mid;
        else ng = mid;
    }
    return ok;
}


int main(int argc, const char * argv[]) {

  ll N; cin >> N;
  POS = vector<pair<ll,ll>>(N);
  for(ll i=0;i<N;i++){
    cin >> POS[i].first >> POS[i].second;
  }
  sort(POS.begin(),POS.end());
  ll ans=0;
  for(ll i=0;i<N;i++){
    for(ll j=i+1;j<N;j++){
      if(POS[i].first == POS[j].first) continue;
      if(POS[i].second == POS[j].second) continue;
      pair<ll,ll> target1 = {POS[i].first,POS[j].second};
      pair<ll,ll> target2 = {POS[j].first,POS[i].second};
      ll bs1 = binary_search(target1);
      ll bs2 = binary_search(target2);
      if(POS[bs1]==target1 && POS[bs2]==target2){
        // cout << "(i,j):(" << i << "," << j << ")" << endl;
        ans++;
      }
    }
  }
  cout << ans/2 << endl;
  return 0;
}