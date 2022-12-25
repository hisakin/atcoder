#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll unsigned long long
using Graph = vector<vector<ll>>;

ll gcd(ll a, ll b) {
    if (b==0) return a;
    else return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

int main(int argc, const char * argv[]) {

  ll N,A,B; cin >> N >> A >>B;

  ll ABlcm = lcm(A,B);
  ll Anum = N/A;
  ll Bnum = N/B;
  ll ABnum = N/ABlcm;

  // cout << "Anum:" << Anum << endl;
  // cout << "Bnum:" << Bnum << endl;
  // cout << "ABlcm:" << ABlcm << endl;
  // cout << "ABnum:" << ABnum << endl;

  ll ans = N*(N+1)/2 - (Anum)*(Anum+1)*A/2 -(Bnum)*(Bnum+1)*B/2 + (ABnum)*(ABnum+1)*ABlcm/2;
  cout << ans << endl;
  
  return 0;
}