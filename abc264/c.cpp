#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {

  ll H1,W1; cin >> H1 >> W1;
  vector<vector<ll>> A(H1,vector<ll>(W1));
  for(ll i=0;i<H1;i++){
    for(ll j=0;j<W1;j++){
      cin >> A[i][j];
    }
  }
  ll H2,W2; cin >> H2 >> W2;
  vector<vector<ll>> B(H2,vector<ll>(W2));
  for(ll i=0;i<H2;i++){
    for(ll j=0;j<W2;j++){
      cin >> B[i][j];
    }
  }

  ll flag_yoko = 0;
  for(ll i=0; i<H2; i++){
    vector<ll> b = B[i];
    for(ll j=0; j<H1; j++){
        vector<ll> a = A[j];
        ll b_index=0;
        for(ll a_index=0; a_index < W1; a_index++){
          if(a[a_index]==b[b_index]){
            b_index++;
          }
        }
        if(b_index<=W2) flag_yoko++;
    }
  }









  return 0;
}