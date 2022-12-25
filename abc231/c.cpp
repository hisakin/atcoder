#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long

vector<ll> A,X;

// index が条件を満たすかどうか
bool isOK(int index, int key) {
    if (A[index] >= key) return true;
    else return false;
}

// 汎用的な二分探索のテンプレ
int binary_search(int key) {
    int ng = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
    int ok = (int)A.size(); // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;

        if (isOK(mid, key)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main(int argc, const char * argv[]) {

  ll N,Q; cin >> N >> Q;
  A = vector<ll>(N);
  X = vector<ll>(Q);

  for(ll i=0;i<N;i++){
    cin >> A[i];
  }
  for(ll i=0;i<Q;i++){
    cin >> X[i];
  }

  sort(A.begin(),A.end());


  for(ll i=0;i<Q;i++){
    ll index = binary_search((int)X[i]);
    // cout << "debug" << endl;
    if(index>=N) cout << 0 << endl;
    else cout << N - index << endl;

  }











  return 0;
}