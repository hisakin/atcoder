#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {

  ll N; cin >> N;
  Graph G(N*2);

  map<ll,ll> toRename;
  map<ll,ll> toOriginal;

  //1ordered
  ll cnt=0;

  //入力受け取り
  vector<ll> A(N),B(N);
  ll firstindex=0;
  for(ll i=0;i<N;i++){
    cin >> A[i] >> B[i];
  }

  ll flag0=false;
  for(ll i=0;i<N;i++){
    if(A[i]==1||B[i]==1){
      flag0 = true;
    } 
  }
  if(!flag0){
    cout << 1 << endl;
    return 0;
  }
  for(ll i=0;i<N;i++){
    A[i]--; B[i]--;;
  }

  for(ll i=0;i<N;i++){
    if(toRename[A[i]]==0){
      toRename[A[i]]=cnt;
      toOriginal[cnt]=A[i];
      cnt++;
    }
  }
  for(ll i=0;i<N;i++){
    if(toRename[B[i]]==0){
      toRename[B[i]]=cnt;
      toOriginal[cnt]=B[i];
      cnt++;
    }
  }

  for(ll i=0;i<N;i++){
    G[toRename[A[i]]].push_back(toRename[B[i]]);
    G[toRename[B[i]]].push_back(toRename[A[i]]);
  }

  queue<ll> que;
  que.push(toRename[0]);
  vector<ll> seen(N*2,-1);
  seen[toRename[0]]=0;

  while(!que.empty()){
    ll current = que.front();
    que.pop();
    for(auto next : G[current]){
      if(seen[next]!=-1) continue;
      seen[next] = seen[current] + 1;
      que.push(next);
    }
  }


  ll ans=1;
  for(ll i=0;i<2*N;i++){
    if(seen[i]!=-1){
      ans = max(toOriginal[i]+1, ans);
    }
  }

  cout << ans << endl;
  return 0;
}