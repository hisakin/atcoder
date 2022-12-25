#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {


  ll N; cin >> N;
  vector<ll> A(N);
  ll S=0;
  for(ll i=0;i<N;i++){
    cin >> A[i];
    S+=A[i];
  }

  vector<ll> SUM(N);
  SUM[0]=S;

  for(ll i=0;i<N-1;i++){
    SUM[i+1] = SUM[i]-A[i]; 
  }

  ll P=0;
  for(ll i=0;i<N;i++){
    if(SUM[i]>=4) P++; 
  }

  cout << P << endl;





}