#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {



  ll N; cin >> N;
  vector<ll> x(N);
  vector<ll> y(N);
  for(ll i=0;i<N;i++){
    cin >> x[i] >> y[i];
  }

  bool ans=false;
  for(ll i=0;i<N;i++){
    for(ll j=i+1;j<N;j++){
      for(ll k=j+1;k<N;k++){
        ll dx1,dx2,dy1,dy2;
        dx1 = x[j]-x[i];
        dx2 = x[k]-x[i];
        dy1 = y[j]-y[i];
        dy2 = y[k]-y[i];
        if(dx1*dy2 == dx2*dy1){
          ans = true;
        }
      }
    }
  }
  if(ans){
    cout << "Yes"  << endl;
  }else{
    cout << "No" << endl;
  }

}