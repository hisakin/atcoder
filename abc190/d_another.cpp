#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;

vector<long long> enum_divisors(long long N) {
  vector<long long> res;
  for (long long i = 1; i * i <= N; ++i) {
      if (N % i == 0) {
          res.push_back(i);
          // 重複しないならば i の相方である N/i も push
          if (N/i != i) res.push_back(N/i);
      }
  }
  // 小さい順に並び替える
  sort(res.begin(), res.end());
  return res;
}

int main(int argc, const char * argv[]) {

  ll N; cin >> N;
  vector<ll> yakusu = enum_divisors(2*N);
  ll ans=0;
  for(auto itr : yakusu){
    if((itr+2*N/itr-1)%2 !=0 || (itr-2*N/itr+1)%2 !=0)
      continue;
    ans++;
  }
  cout << ans << endl;
  return 0;
}