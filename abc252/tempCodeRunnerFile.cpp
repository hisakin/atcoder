#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {


  ll N; cin >> N;

  vector<ll> A(N);
  for(ll i=0;i<N;i++){
    cin >> A[i];
  }

  vector<ll> X[2*100000+1,0];

  for(ll i=0;i<N;i++){
    X[A[i]]++;
  }

  ll cnt=0;
  for(ll i=0;i<2*100000+1;i++){
    if(X[A[i]]>0){
      cnt++;
    }
  }

  cout << cnt*(cnt-1)*(cnt-2)/6 << endl;


}