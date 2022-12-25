#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long

bool comp(pair<ll,ll>& a, pair<ll,ll>&b){
  return a.second < b.second;
}

int main(int argc, const char * argv[]) {

  ll N; cin >> N;
  string S; cin >> S;

  vector<ll> W(N);
  for(ll i=0;i<N;i++){
    cin >> W[i];
  }

  vector<pair<ll,ll>> P(N);

  for(ll i=0;i<N;i++){
    P[i].first = S[i] - '0';
    P[i].second = W[i];
  }

  cout << "[sort前]" << endl;

  for(ll i=0;i<N; i++){
    cout << P[i].first << " ";
  }
  cout << endl;

  for(ll i=0;i<N; i++){
    cout << P[i].second << " ";
  }
  cout << endl;

  sort(P.begin(), P.end(), comp);

  cout << "[sort後]" << endl;

  for(ll i=0;i<N; i++){
    cout << P[i].first << " ";
  }
  cout << endl;

  for(ll i=0;i<N; i++){
    cout << P[i].second << " ";
  }
  cout << endl;








}