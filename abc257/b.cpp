#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {


  ll N, K, Q; cin >> N >> K >> Q;
  vector<ll> A(K), L(Q);
  for(ll i=0;i<K;i++){
    cin >> A[i];
    A[i]--;
  }

 for(ll i=0;i<Q;i++){
    cin >> L[i];
    L[i]--;
  }

  for(ll i=0;i<Q;i++){
    if(A[L[i]]==N-1) continue;
    if(A[ L[i] + 1 ] == A[ L[i] ] + 1   ) continue;
    A[L[i]]++;
  }
  
  for(ll i=0;i<K; i++){
    cout << A[i]+1 << " ";
  }
  cout << endl;

}