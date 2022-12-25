#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {

  ll N, M, X, T, D;
  cin >> N >> M >> X >> T >> D;
  
  ll ans;
  if(M > X){
    ans = T; 
  }else{
    ans = T - X*D + M*D; 
  }

  cout << ans << endl;

}