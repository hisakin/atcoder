#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {

  ll X,A,D,N;
  cin >> X >> A >> D >> N;

  ll maxS = D*(N-1) + A;
  ll minS = A;

  if(maxS<minS) swap(maxS,minS);

  ll ans;
  if(X>=maxS){
    ans = X-maxS;
    cout << ans << endl;
    return 0;
  }
  else if(X<=minS){
    ans = minS-X;
    cout << ans << endl;
    return 0;
  }
  ll k = (X-A)/D;
  ll left  = abs(X-(k*D+A));
  ll right = abs(X-((k+1)*D+A));

  ans = min(left,right);
  cout << ans << endl;
  return 0;
}