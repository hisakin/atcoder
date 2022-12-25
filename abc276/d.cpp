#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;

ll gcd(ll a, ll b){
  if(a%b == 0){
    return b;
  }else{
    return gcd(b, a%b);
  }
}


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
    }

    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}



int main(int argc, const char * argv[]) {

  ll N; cin >> N;
  vector<ll> A(N);
  for(ll i=0;i<N;i++){
    cin >> A[i];
  }

  ll gcdall = gcd(A[0],A[1]);
  for(ll i=2;i<N;i++){
    gcdall = gcd(A[i],gcdall);
  }

  // cout << "gcdall:" << gcdall << endl;


  ll ans=0;
  for(ll i=0;i<N;i++){
    if(A[i]==gcdall) continue;
    ll divnum = A[i]/gcdall;
    vector<pair<ll,ll> > res = prime_factorize(divnum);
    // cout << "res.size:" << res.size() << endl;

    if(res.size()>=3){
      ans=-1;
      break;
    }

    for(ll j=0;j<res.size();j++){
      if(res[j].first != 2 && res[j].first != 3){
        ans=-1;
        break;
      }
      ans += res[j].second;
    }
    if(ans==-1) break;
  }

  cout << ans << endl;

  return 0;
}