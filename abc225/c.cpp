#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {

  ll N,M; cin >> N >> M;
  vector<vector<ll>> B(N,vector<ll>(M));
  for(ll i=0;i<N;i++){
    for(ll j=0;j<M;j++){
      cin >> B[i][j];
    }
  }


  bool ans = true;

  ll index_i = (B[0][0] - 1) / 7;
  ll index_j = (B[0][0] - 1) % 7;

  if(index_j + M - 1 > 6) ans=false;
  // if(index_i + N - 1)


  for(ll i=0;i<N;i++){
    for(ll j=1;j<M;j++){
      if(B[i][j]!=B[i][j-1]+1){
        ans = false;
      }
    }
  }
  // for(ll i=1;i<N;i++){
  //   for(ll j=0;j<M;j++){
  //     if(B[i][j]!=B[i-1][j]+7){
  //       ans = false;
  //     }
  //   }
  // }
  for(ll j=0;j<M;j++){
    for(ll i=1;i<N;i++){
      if(B[i][j]!=B[i-1][j]+7){
        ans = false;
      }
    }
  }
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}