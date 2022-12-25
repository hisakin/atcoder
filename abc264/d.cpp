#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {

  string S; cin >> S;
  string ATCODER = "atcoder";
  map<char,ll> MAP;
  for(ll i=0;i<S.size();i++){
    MAP[ATCODER[i]]=i;
  }
  vector<ll> list(S.size());
  for(ll i=0;i<S.size();i++){
    list[i] = MAP[S[i]];
  }

  ll sum=0;
  for(ll i=0;i<S.size();i++){
    for(ll j=0;j<i;j++){
      if(list[j]>list[i])
        sum++;
    }
  }

  cout << sum << endl;




  return 0;
}