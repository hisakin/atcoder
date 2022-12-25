#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;

struct info{
  ll AOKI;
  ll TAKAHASHI;
  ll TOTAL_V;
};

// 比較関数を定義
bool asc( const info& left, const info& right ) {
    return left.TOTAL_V > right.TOTAL_V;
}


int main(int argc, const char * argv[]) {

  ll N; cin >> N;
  vector<info> INFO(N);
  ll total_aoki = 0;
  ll total_takahashi = 0;
  for(ll i=0;i<N;i++){
    ll a,b;  cin >> a >> b;
    INFO[i].AOKI = a;
    INFO[i].TAKAHASHI = b;
    INFO[i].TOTAL_V = a + b + a;
    total_aoki += a;
  }
  sort(INFO.begin(),INFO.end(),asc);

  // for(ll i=0;i<N;i++){
  //   cout << "AOKI:" << INFO[i].AOKI << " TAKAHASHI:" << INFO[i].TAKAHASHI << " TOTAL_V:" << INFO[i].TOTAL_V << endl;
  // }

  ll ans;
  for(ll i=0;i<N;i++){
    total_takahashi += INFO[i].AOKI + INFO[i].TAKAHASHI;
    total_aoki -= INFO[i].AOKI;;
    if(total_takahashi > total_aoki){
      ans = i+1;
      break;
    }
  }
  cout << ans << endl;

  return 0;
}