#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {

  vector<ll> H(3);
  vector<ll> W(3);
  for(ll i=0;i<3;i++){
    cin >> H[i];
  }

  for(ll i=0;i<3;i++){
    cin >> W[i];
  }


  ll ans=0;
  for(ll d=1;d<=28;d++){
    for(ll e=1;e<=28;e++){
      for(ll g=1;g<=28;g++){
        for(ll h=1;h<=28;h++){
          ll a = W[0]-d-g;
          ll b = W[1]-e-h;
          ll c = H[0]-W[0]+d+g-W[1]+e+h;
          ll f = H[1]-d-e;
          ll i = H[2]-g-h;

          if(a<=0 || b <=0 || c<=0 || f<=0 || i<=0) continue;

          if(a+b+c==H[0] && d+e+f==H[1] && g+h+i==H[2] && a+d+g==W[0] && b+e+h==W[1] && c+f+i==W[2]){
            ans++;
          }
        }
      }
    }
  }

  cout << ans << endl;
  return 0;
}