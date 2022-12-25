#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {

  ll N,M; cin >> N >> M;
  Graph G(N);
  vector<ll> A(M),B(M);
  for(ll i=0;i<M;i++){
    cin >> A[i] >> B[i];
    A[i]--; B[i]--;
    G[A[i]].push_back(B[i]);
  }

  ll ans=0;
  for(ll s=0;s<N;s++){
    vector<ll> seen(N,-1);
    seen[s]=0;
    stack<ll> STACK;
    STACK.push(s);
    while(!STACK.empty()){
      ll current = STACK.top();
      STACK.pop();
      for(auto next : G[current]){
        if(seen[next]>=0) continue;
        seen[next]=seen[current]+1;
        STACK.push(next);
      }
    }
    ll cnt=0;
    for(ll i=0;i<N;i++){
      if(seen[i]>=0){
        cnt++;
        // cout << seen[i] << " ";
      }
    }
    // cout << endl;
    ans += cnt;
  }

  cout << ans << endl;

  return 0;
}