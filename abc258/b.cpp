#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {


  ll N; cin >> N;
  vector<vector<ll>> A(N,vector<ll>(N));
  for(ll i=0;i<N;i++){
    for(ll j=0;j<N;j++){
      char c;
      cin >> c;
      A[i][j]=c-'0';
    }
  }


  ll ans = 0;
  for(ll i=0;i<N;i++){
    for(ll j=0;j<N;j++){
      //上
      ll temp = 0;
      for(ll k=0;k<N;k++ ){
        temp = temp*10 + A[i][(j+k)%N];
      } ans = max(ans,temp);

      //下
      temp = 0;
      for(ll k=0;k<N;k++ ){
        temp = temp*10 + A[i][(j-k+N)%N];
      } ans = max(ans,temp);

      //右
      temp = 0;
      for(ll k=0;k<N;k++ ){
        temp = temp*10 + A[(i+k)%N][j];
      } ans = max(ans,temp);

      //右
      temp = 0;
      for(ll k=0;k<N;k++ ){
        temp = temp*10 + A[(i-k+N)%N][j];
      } ans = max(ans,temp);

      //右上
      temp = 0;
      for(ll k=0;k<N;k++ ){
        temp = temp*10 + A[(i+k)%N][(j-k+N)%N];
      } ans = max(ans,temp);
 
      //右下
      temp = 0;
      for(ll k=0;k<N;k++ ){
        temp = temp*10 + A[(i+k)%N][(j+k)%N];
      } ans = max(ans,temp);

      //左下
      temp = 0;
      for(ll k=0;k<N;k++ ){
        temp = temp*10 + A[(i-k+N)%N][(j+k)%N];
      } ans = max(ans,temp);

      //左上
      temp = 0;
      for(ll k=0;k<N;k++ ){
        temp = temp*10 + A[(i-k+N)%N][(j-k+N)%N];
      } ans = max(ans,temp);

    }
  } 
 cout << ans << endl;


}