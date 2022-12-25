#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;

ll modc = 998244353;

int main(int argc, const char * argv[]) {

  ll A,B,C,D,E,F;
  cin >> A >> B >> C >> D >> E >> F;
  A = A % modc;
  B = B % modc;
  C = C % modc;
  D = D % modc;
  E = E % modc;
  F = F % modc;

  ll left = (((A * B) % modc ) * C )%modc;
  ll right = (((D * E) % modc ) * F )%modc;
  ll ans = (left - right + modc ) % modc;
  cout << ans << endl;

  return 0;
}