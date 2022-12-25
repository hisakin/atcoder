#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {

  ll N; cin >> N;
  vector<ll> H(N);
  ll ans = 0;
  ll index_ans;
  for(ll i=0;i<N;i++){
    cin >> H[i];
    if(ans < H[i]){
      ans = H[i];
      index_ans = i;
    }
  }
  cout << index_ans + 1 << endl;

  return 0;
}