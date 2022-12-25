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

  ll ans=0;
  while(true){
    bool flag=true;
    for(ll i=0;i<N;i++){
      if(A[i]%2==1) flag=false;
    }

    if(flag==false) break;

    for(ll i=0;i<N;i++){
      A[i] = A[i]/2;
    }
    ans++;
  }

  cout << ans << endl;




  return 0;
}