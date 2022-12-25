#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;

set<ll> SET;

vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back({a, ex});
        SET.insert(a);
    }

    // 最後に残った数について
    if (N != 1){
      res.push_back({N, 1});
      SET.insert(N);
    }
    return res;
}

int main(int argc, const char * argv[]) {


  ll N,M; cin >> N >> M;
  vector<ll> A(N);
  for(ll i=0;i<N;i++) cin >> A[i];
  for(ll i=0;i<N;i++){
  const auto &res = prime_factorize(A[i]);
  }
  vector<bool> MLIST(M+1,true);
  for(auto val : SET){
    // cout << "val:" << val << endl;
    ll addval = val;
    while(val<=M){
      MLIST[val]=false;
      val += addval;
    }
  }

  vector<ll> ANSLIST;
  for(ll i=1;i<=M;i++){
    if(MLIST[i]) ANSLIST.push_back(i);
  }
  cout << ANSLIST.size() << endl;
  for(ll i=0;i<ANSLIST.size();i++){
    cout << ANSLIST[i] << endl;
  }

  return 0;
}