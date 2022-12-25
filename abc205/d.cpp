#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll unsigned long long
using Graph = vector<vector<ll>>;

vector<ll> A,B;

// index が条件を満たすかどうか
bool isOK(ll index, ll key) {
    if (B[index] >= key) return true;
    else return false;
}

// 汎用的な二分探索のテンプレ
ll binary_search(ll key) {
    ll ng = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
    ll ok = (ll)B.size(); // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (llabs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;

        if (isOK(mid, key)) ok = mid;
        else ng = mid;
    }
    return ok;
}



int main(int argc, const char * argv[]) {

  // // 追加２, 以降 cin の入力元が 'input.txt' になる
  // std::ifstream in("after_00.txt");
  // std::cin.rdbuf(in.rdbuf());

  ll N,Q; cin >> N >> Q;
  A.resize(N+1);
  B.resize(N+1);
  A[0]=0; B[0]=0;
  for(ll i=1;i<=N;i++){
    cin >> A[i];
    B[i] = (A[i]-A[i-1] - 1) + B[i-1];
  }

  vector<ll> K(Q);
  for(ll i=0;i<Q;i++){
    // cout << "Q:" << i << endl;
    ll K; cin >> K;
    ll index = binary_search(K);
    ll ans;
    if(index==B.size()){
      ans = A.back() + K - B.back();
      // cout << "サイズ越え" << endl;
      // cout << "B.back : " << B.back() << endl;
    }else{
      ans = A[index] - 1 - (B[index] - K);
      // cout << "サイズ以内" << endl;
    }
    cout << ans << endl;
  }

  return 0;
}