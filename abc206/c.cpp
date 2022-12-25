#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {

  ll N;  cin >> N;
  vector<ll> A(N);
  for(ll i=0;i<N;i++){
    cin >> A[i];
  }
  sort(A.begin(),A.end());

  vector<ll> B;

  B.push_back(1);
  ll b=0;
  for(ll i=1;i<N;i++){
    if(A[i]==A[i-1]){
      B[b]++;
    }
    else{
      B.push_back(1);
      b++;
    }
  }


  ll total_num = N;
  ll ans=0;
  for(ll i=0;i<B.size()-1;i++){
    total_num -= B[i];
    ans+=B[i]*total_num;
  }

  cout << ans << endl;

  return 0;
}