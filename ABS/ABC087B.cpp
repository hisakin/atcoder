#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {


  ll A,B,C,X;
  cin >> A >> B >> C >> X;

  ll ans=0;
  for(ll a=0;a<=A;a++){
    for(ll b=0;b<=B;b++){
      for(ll c=0;c<=C;c++){
        if(500*a+100*b+50*c==X) ans++;
      }
    }
  }

  cout << ans << endl;



  return 0;
}