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

  vector<ll> X(2*100000+1);

  for(ll i=0;i<2*100000+1;i++){
    X[i]=0;
  }

  for(ll i=0;i<N;i++){
    X[A[i]]++;
  }

  ll cnt=0,cnt2=1;
  for(ll i=0;i<2*100000+1;i++){
    if(X[i]>0){
      cnt++;
      cnt2*=X[i];
    }
  }

  cout << "cnt=" << cnt << endl;
  cout << "cnt2=" << cnt2 << endl;

  cout << "xC3 = " <<cnt*(cnt-1)*(cnt-2)/6 << endl;


  cout << (cnt*(cnt-1)*(cnt-2)/6)*cnt2 << endl;


}