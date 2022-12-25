#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {


  ll N; cin >> N;
  vector<ll> a(N);
  for(ll i=0;i<N;i++){
    cin >> a[i];
    a[i]--;
  }

  ll match_cnt=0;
  ll crossmatch_cnt=0;
  for(ll i=0;i<N;i++){
    if(i==a[i]){
      match_cnt++;
      continue;
    }
    if(i == a[a[i]] && i < a[i]){
      crossmatch_cnt++;
      continue;
    }
  }

  ll comb_match_cnt = (match_cnt)*(match_cnt-1)/2;

  // cout << "match_cnt :" << match_cnt << endl;
  // cout << "comb_match_cnt :" << comb_match_cnt << endl;
  // cout << "crossmatch_cnt :" << crossmatch_cnt << endl;

  cout << comb_match_cnt + crossmatch_cnt << endl;
  return 0;
}