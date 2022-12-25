#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll unsigned long long

ll N, X,ans=0;
vector<vector<ll>> A; 

void dfs(ll index, ll cnt){


  if(index==N){
    if(cnt==X){
      ans++;
    }
    return ;
  }

  for(ll i=0;i<A[index].size();i++){
    if(X/cnt + 1 < A[index][i]) continue;
    dfs(index+1,cnt*A[index][i]);
  }

}


int main(int argc, const char * argv[]) {

  cin >> N >> X;
  for(ll i=0;i<N; i++){
    ll L; cin >> L;
    vector<ll> a(L);
    for(ll k=0;k<L;k++){
      cin >> a[k];
    }
    A.push_back(a);
  }

  dfs(0,1);

  cout << ans << endl;

  return 0;
}