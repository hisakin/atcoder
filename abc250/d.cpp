#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;

// 1 以上 N 以下の整数が素数かどうかを返す
vector<bool> Eratosthenes(ll N) {
    // テーブル
    vector<bool> isprime(N+1, true);

    // 1 は予めふるい落としておく
    isprime[1] = false;

    // ふるい
    for (ll p = 2; p <= N; ++p) {
        // すでに合成数であるものはスキップする
        if (!isprime[p]) continue;

        // p 以外の p の倍数から素数ラベルを剥奪
        for (ll q = p * 2; q <= N; q += p) {
            isprime[q] = false;
        }
    }

    // 1 以上 N 以下の整数が素数かどうか
    return isprime;
}



int main(int argc, const char * argv[]) {

  ll N; cin >> N;
  ll N_3 = (ll)cbrt(N);
  ll ans=0;
  vector<bool> EratosList = Eratosthenes(N_3);
  vector<ll> PrimeList;
  for(ll i=2;i<EratosList.size();i++){
    if(EratosList[i]){
      PrimeList.push_back(i);
    }
  }

  // for(ll i=0;i<PrimeList.size();i++){
  //   cout << PrimeList[i] << " ";
  // }
  // cout << endl;

  for(ll i=0;i<PrimeList.size();i++){
    ll q = PrimeList[i]; 
    ll q_3 = q*q*q;
    for(ll j=0;j<PrimeList.size();j++){
      ll p = PrimeList[j];
      if(p>=q) continue;
      if(N/q_3 < p) break;
      if(q_3*p <= N){
        ans++;
      }
    }
  }

  cout << ans << endl;
  return 0;
}