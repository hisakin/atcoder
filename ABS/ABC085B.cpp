#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {

  ll N;cin >> N;
  vector<ll> d(N);
  for(ll i=0;i<N;i++){
    cin >> d[i];
  }

  sort(d.begin(),d.end(),greater<ll>());

  ll ans=1;
  for(ll i=1;i<N;i++){
    if(d[i-1]>d[i]) ans++;
  }

  cout << ans << endl;




  return 0;
}