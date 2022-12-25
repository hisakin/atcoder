#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {

  ll N, K; cin >> N >> K;
  vector<ll> A(K);
  for(ll i=0;i<K;i++){
    cin >> A[i];
  }

  sort(A.begin(),A.end());

  ll takahashi=0;
  ll aoki=0;
  ll current_turn=0;
  ll next_turn=0;

  for(ll i=K-1;i>=0;i--){
    // cout << "i:" << i << endl;
    // cout << "N:" << N << endl;
    if(N<A[i]) continue;
    if(N<=0) break;

    ll div = N/A[i];
    next_turn = (current_turn + div%2)%2;

    // cout << "current_turn:" << current_turn << endl;
    // cout << "next_turn:" << next_turn << endl;

    if(next_turn == current_turn){
      takahashi += ((div/2)*A[i]);
      aoki += ((div/2)*A[i]);
    }
    else if(next_turn==1 && current_turn==0){
      takahashi += ((div/2)*A[i]) + A[i] ;
      aoki += ((div/2)*A[i]);
      current_turn=1;
    }
    else if(next_turn==0 && current_turn==1){
      takahashi += ((div/2)*A[i]) ;
      aoki += ((div/2)*A[i]) + A[i];
      current_turn=0;
    }

    // cout << "takahashi:" << takahashi << endl;
    // cout << "aoki:" << aoki << endl;
    // cout  << endl;

    N = N - div*A[i];

  }
  cout << takahashi << endl;

  return 0;
}