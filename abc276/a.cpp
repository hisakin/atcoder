#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {

  string S; cin >> S;
  ll ans=-1;
  for(ll i=S.size()-1;i>=0;i--){
    if(S[i]=='a'){
      ans = i + 1;
      break;
    }
  }

  cout << ans << endl;


  return 0;
}