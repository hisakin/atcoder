#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {

  ll N; cin >> N;
  vector<ll> A(N),B(N);
  for(ll i=0;i<N;i++){
    cin >> A[i];
    B[i] = A[i];
  }

  sort(B.begin(),B.end());
  map<ll,ll> MAP;
  for(ll i=0;i<N;i++){
    MAP[B[i]]++;
  }

  vector<ll> NUM;
  NUM.push_back(B[0]);
  // ll cnt=0;
  for(ll i=1;i<N;i++){
    if(B[i]==B[i-1]) continue;
    NUM.push_back(B[i]);
    // cnt++;
  }

  // cout << "デバッグ" << endl;
  // for(ll i=0;i<NUM.size();i++){
  //   cout << NUM[i] << " ";
  // }
  // cout << endl;
  // cout << "デバッグ end" << endl;

  for(ll i=0;i<N;i++){
    if(i>=NUM.size()){
      cout << 0 << endl;
      continue;
    }
    cout << MAP[NUM[NUM.size()-1-i]] << endl;
  }

  return 0;
}