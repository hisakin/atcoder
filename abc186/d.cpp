#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {

  ll N; cin >> N;
  vector<ll> A(N);
  ll sum=0;
  for(ll i=0;i<N;i++){
    cin >> A[i];
    sum += A[i];
  }
  sort(A.begin(),A.end());
  ll ans=0;
  for(ll i=0;i<N-1;i++){
    ans += sum - A[i]*(N-i);
    sum -= A[i];
  }
  cout << ans << endl;
  return 0;
}