#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {

  ll N; cin >> N;
  vector<ll> A(N+1);
  for(ll i=1;i<=N;i++) cin >> A[i];

  vector<ll> LIST(2*N+2,0);
  for(ll i=1;i<=N;i++){
    LIST[2*i] = LIST[A[i]] + 1;
    LIST[2*i+1] = LIST[A[i]] + 1;
  }
  for(ll i=1;i<2*N+2;i++){
    cout << LIST[i] << endl;
  }






  return 0;
}