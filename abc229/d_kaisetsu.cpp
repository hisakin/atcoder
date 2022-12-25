#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {

  string S; cin >> S;
  ll K; cin >> K;
  ll ans=0;
  ll N = S.size();

  vector<ll> cnt(N+1,0);
  for(ll i=0;i<N;i++){
    if(S[i]=='.') cnt[i+1] = cnt[i] + 1;
    else cnt[i+1] = cnt[i];
  }

  ll right=0;
  for(ll left=0;left<N;left++){
    while(right<N && cnt[right+1]-cnt[left]<=K){
      right++;
    }
    ans = max(ans,right-left);
    // cout << "left:" << left << "  right:" << right << endl;
  }
  cout << ans << endl;

  return 0;
}