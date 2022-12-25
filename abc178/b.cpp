#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {


  ll a,b,c,d; cin >> a >> b >> c >>d;
  ll Z[4];
  Z[0]=a*c,Z[1]=a*d,Z[2]=b*c,Z[3]=b*d;
  ll i;
  ll max = Z[0];
  for(i=0;i<4;i++){
    if(max<Z[i]){
      max = Z[i];
    }
  }
  cout << max << endl;
}