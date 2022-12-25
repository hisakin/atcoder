#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;

// index が条件を満たすかどうか
bool isOK(int index, int key, vector<ll> &a) {
    if (a[index] >= key) return true;
    else return false;
}

// 汎用的な二分探索のテンプレ
int binary_search(int key, vector<ll> &a) {
    int ng = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
    int ok = (int)a.size(); // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;

        if (isOK(mid, key,a)) ok = mid;
        else ng = mid;
    }
    return ok;
}


int main(int argc, const char * argv[]) {


  ll N; cin >> N;
  vector<ll> A(N);
  for(ll i=0;i<N;i++){
    cin >> A[i];
  }
  ll Q; cin >> Q;
  ll XMAX = 2*100000;
  vector<vector<ll>> INDEX(XMAX+1);

  for(ll i=0;i<N;i++){
    INDEX[A[i]].push_back(i);
  }

  for(ll i=0;i<Q;i++){
    ll L,R,X; cin >> L >> R >> X; L--; R--;
    if(INDEX[X].size()==0){
      cout << 0 << endl;
      continue;
    }
    ll L_index = binary_search(L,INDEX[X]);
    ll R_index = binary_search(R,INDEX[X]);
    ll plus1 = 0;
    if(INDEX[X][R_index]==R) plus1=1;
    // cout << "L_index:" << L_index << "  R_index:" << R_index << "  plus1:" << plus1 << endl;
    // for(ll i=0;i<INDEX[X].size();i++){
    //   cout << INDEX[X][i] << " ";
    // }
    // cout << endl;
    cout << R_index - L_index + plus1 << endl;

  }





  return 0;
}