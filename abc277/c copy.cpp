#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {

  ll N; cin >> N;
  Graph G(N);
  vector<ll,ll> renode(2*N,-1);

  //入力受け取り
  vector<ll> A(N),B(N);
  ll cnt=0;
  for(ll i=0;i<N;i++){
    cin >> A[i] >> B[i];
    A[i]--; B[i]--;
    renode[cnt]=A[i]; cnt++;
    renode[cnt]=B[i]; cnt++;
  }

    G[A[i]].push_back(B[i]);
    G[B[i]].push_back(A[i]);
  //リネーム
  for(ll i=0;i<N;i++){
    pair<ll,ll> pa;
    if(exist[A[i]]==0){
      pa = {A[i],cnt};
      cnt++;
      P.push_back(pa);
    }
    pair<ll,ll> pb;
    if(exist[B[i]]==0){
      pb = {B[i],cnt};
      cnt++;
      P.push_back(pb);
    }
  }

  for(ll i=0;i<N;i++){
  }

  queue<ll> que;
  que.push(0);
  vector<ll> seen(N,-1);
  seen[0]=0;

  while(!que.empty()){
    ll current = que.front();
    que.pop();
    for(auto next : G[current]){
      if(seen[next]!=-1) continue;
      seen[next] = seen[current] + 1;
      que.push(next);
    }
  }

  for(ll i=0;i<N;i++){
    cout << "seen[" << i << "]:" << seen[i] << endl;
  }

  ll ans=1;
  for(ll i=1;i<N;i++){
    ans = max(seen[i]+1,ans);
    // if(seen[i]!=-1){
    //   ans = i+1;
    // }
  }

  cout << ans << endl;
  return 0;
}