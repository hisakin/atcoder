#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;

vector<ll> A;
vector<ll> S;

// index が条件を満たすかどうか
bool isOK(ll index, ll key) {
    if (A[index] >= key) return true;
    else return false;
}

// 汎用的な二分探索のテンプレ
ll binary_search(ll key) {
    ll ng = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
    ll ok = (ll)A.size(); // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;

        if (isOK(mid, key)) ok = mid;
        else ng = mid;
    }
    return ok;
}


int main(int argc, const char * argv[]) {


  ll N,Q; cin >> N >> Q;
  A = vector<ll>(N);
  S = vector<ll>(N+1);
  for(ll i=0;i<N;i++) cin >> A[i];
  sort(A.begin(),A.end());

  S[0]=0;
  for(ll i=0;i<N;i++){
    S[i+1]=S[i]+A[i];
  }


  vector<ll> X(Q);
  for(ll i=0;i<Q;i++) cin >> X[i];

  for(ll i=0;i<Q;i++){
    ll index = binary_search(X[i]);
    // cout << "index:" << index << endl;
    ll ans = 0;
    ans = abs((N-index)*X[i] - (S[N]-S[index])) + abs((index)*X[i] - (S[index]-S[0]));
    cout << ans << endl;
  }

  return 0;
}