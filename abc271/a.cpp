#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {

  ll N; cin >> N;
  string S = "0123456789ABCDEF";

  if(N>=16){

    ll div = N/16;
    ll mod = N%16;
    cout << S[div] << S[mod] << endl;

  }else{
    ll mod = N%16;
    cout << "0" << S[mod] << endl;
  }





  return 0;
}