#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;

ll MODCST = 998244353;

int main(int argc, const char * argv[]) {

  unsigned ll N; cin >> N;
  ll ans=0;
  ll digit = log10(N)+1;
  while(digit>1){
    unsigned ll target = pow(10,digit-1);
    unsigned ll temp = ((N-target+1)%MODCST)*((N-target+1+1)%MODCST)/2;
    ans = (ans + temp%MODCST)%MODCST;
    ans = ans % MODCST;
    N = target - 1;
    digit--;
  }
  //N/10==0の時の処理をかく
  ans += (N+1)*N/2;
  ans = ans % MODCST;

  cout << ans << endl;

  return 0;
}