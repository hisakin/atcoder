#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {

    double A,B; cin >> A >> B;
    double ans = round( ((B/A)*1000)) /1000;

    cout << fixed << setprecision(3) << ans << endl;

  return 0;
}