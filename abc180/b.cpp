#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {

ll N;cin >> N;
vector<long double> x(N);
for(ll i=0;i<N;i++){
  cin >> x[i];
}

long double ans1=0,ans2=0,ans3=0;

for(ll i=0;i<N;i++){
  ans1 += abs(x[i]);
}

for(ll i=0;i<N;i++){
  ans2 += abs(x[i])*abs(x[i]);
}
ans2 = sqrt(ans2);

for(ll i=0;i<N;i++){
  if(ans3 < abs(x[i]))
    ans3 = abs(x[i]);
}

cout << fixed << setprecision(10);
cout << ans1 << endl;
cout << ans2 << endl;
cout << ans3 << endl;

}