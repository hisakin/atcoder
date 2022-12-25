#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {

  ll N,Q; cin >> N >> Q;
  vector<vector<ll>> A(N);
  for(ll i=0;i<N;i++){
    ll L; cin >> L;
    for(ll j=0;j<L;j++){
      ll temp; cin >> temp;
      A[i].push_back(temp);
    }
  }
  vector<ll> S(Q);
  vector<ll> T(Q);

  for(ll i=0;i<Q;i++){
    cin >> S[i] >> T[i];
    S[i]--; T[i]--;
  }

  for(ll i=0;i<Q;i++){
    cout << A[S[i]][T[i]] << endl;
  }






  return 0;
}