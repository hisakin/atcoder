#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {

  ll N; cin >> N;
  vector<ll> A(N);
  map<ll,ll> MAP;
  for(ll i=0;i<N;i++){
    ll temp; cin >> temp;
    if(MAP[temp]==0){
      A[i]=temp;
      MAP[A[i]]++;
    }
    else {
      A[i]=10000000000;
    }
  }


  if(A.size()==1){
    if(A[0]==1){
      cout << 1 << endl;
      return 0;
    }
    else{
      cout << 0 << endl;
      return 0;
    }
  }
  //ここより、N>=2以上に限定

  sort(A.begin(),A.end());

  // for(ll i=0;i<N;i++){
  //   cout << A[i] << " ";
  // }cout << endl;

  ll ans=0;
  ll cnt=1;
  for(ll i=0;i<A.size();cnt++){
    // cout << "i:" << i << "  A.size():" << A.size() << endl;
    if(A[i]==cnt){
      ans++;
      i++;
      continue;
    }
    else{
      if(i>=A.size()-1) break;
      A.pop_back();
      A.pop_back();
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}