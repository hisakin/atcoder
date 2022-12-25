#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;

vector<ll> A;
vector<ll> S;


// index が条件を満たすかどうか
bool isOK(int index, int key) {
    if (S[index] >= key) return true;
    else return false;
}

// 汎用的な二分探索のテンプレ
int binary_search(int key) {
    int ng = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
    int ok = (int)S.size(); // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;

        if (isOK(mid, key)) ok = mid;
        else ng = mid;
    }
    return ok;
}



int main(int argc, const char * argv[]) {

  ll N, P , Q, R; cin >> N >> P >> Q >> R;
  A = vector<ll>(N);
  S = vector<ll>(N+1); S[0]=0;
  for(ll i=0;i<N;i++){
    cin >> A[i];
    S[i+1] = S[i] + A[i];
  }

  ll x,y,z,w;
  bool ans=false;
  for(ll i=0;i<N+1;i++){
    x = i;
    y = binary_search(P+S[x]);
    cout << "y:" << y << endl;
    if(y>N || y<0){
      ans=false;
      break;
    }
    if(S[y] != P+S[x]){
      continue;
    }

    z = binary_search(Q+S[y]);
    if(z>N || z<0){
      ans=false;
      break;
    }
    if(S[z] != Q+S[y]){
      continue;
    }

    w = binary_search(R+S[z]);
    if(w>N || w<0){
      ans=false;
      break;
    }
    if(S[w] != R+S[z]){
      continue;
    }

    ans = true;

  }

  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}