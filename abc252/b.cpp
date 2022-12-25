#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {

  ll N,K; cin >> N >> K;
  vector<ll> A(N);
  ll max=0;
  for(ll i=0;i<N;i++){
    cin  >> A[i];
    if(max < A[i]){
      max = A[i];
    }
  }

  vector<bool> array_max(N,false);
  for(ll i=0;i<N;i++){
    if(A[i]==max){
      array_max[i]=true;
    }
  }


  vector<ll> B(K);
  bool ans=false;
  for(ll i=0;i<K;i++){
    cin >> B[i];
    B[i] = B[i] - 1;
  }

  for(ll i=0;i<N;i++){
    for(ll k=0;k<K;k++){
      if(array_max[i] && B[k]==i){
        ans = true;
      }
    }
  }


  if(ans){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }


}