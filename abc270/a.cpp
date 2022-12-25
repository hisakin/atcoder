#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {

  ll A,B; cin >> A >> B;

  ll ans=0;
  if(A%2==1||B%2==1) ans+=1;

  if(A>=4 || B>=4) ans+=4;

  if(A==2||A==3||A==6||A==7||B==2||B==3||B==6||B==7) ans+=2;

  cout << ans << endl;






  return 0;
}