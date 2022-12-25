#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {

  ll N,X; cin >> N >> X;
  vector<ll> P(N);
  ll ans=0;
  for(ll i=0;i<N;i++){
    cin >> P[i];
    if(X==P[i]){
      ans=i+1;
    }
  }
  cout << ans << endl;





  return 0;
}