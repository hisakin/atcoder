#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {


  ll N; cin >> N;
  vector<ll> a(N);
  for(ll i=0;i<N;i++){
    cin >> a[i];
  }

  sort(a.begin(),a.end(),greater<ll>());

  ll alice=0, bob=0;
  for(ll i=0;i<N;i++){
    if(i%2==0){
      alice += a[i];
    }else{
      bob += a[i];
    }
  }

  cout << alice - bob << endl;






  return 0;
}