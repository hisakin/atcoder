#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {

  string s;
  cin >> s;

  ll ans=0;
  for(ll i=0;i<s.size();i++){
    if(s[i]=='1') ans++;
  }


  cout << ans << endl;

  return 0;
}