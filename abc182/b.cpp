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

  ll maxG=0;
  ll maxk;
  ll temp;
  for(ll i=2;i<=1000;i++){
    temp=0;
    for(ll j=0;j<N;j++){
      if(A[j]%i==0){
        temp++;
      }
    }
    if(temp>maxG){
      maxG=temp;
      maxk = i;
    }
  }

  cout << maxk << endl;

}