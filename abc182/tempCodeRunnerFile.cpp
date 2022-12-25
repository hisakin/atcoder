#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {


  ll N; cin >> N;
  ll N_val = N;

  vector<ll> A;
  ll keta=0;
  while(N_val/10 != 0){
    keta++;
    A.push_back((N_val%10)%3);
    N_val = N_val/10;
  }
  A.push_back(N_val%3);
  keta++;


  ll div = N%3;
  ll ans=0;
  if(div==0){
    ans = 0;
  }else{
    ll cnt2=0,cnt1=0;
    for(ll i=0;i<A.size();i++){
      if(A[i]==2) cnt2++;
      if(A[i]==1) cnt1++;
    }
    if(div==1){
      if(cnt1>=1){
        ans=1;
      }else if(cnt2>=2){
        ans=2;
      }else{
        ans=-1;
      }
    }else{
      if(cnt2>=1){
        ans=1;
      }else if(cnt1>=2){
        ans=2;
      }else{
        ans=-1;
      }
    }
  }


  if(ans>=keta){
    ans=0;
  }
  cout << ans << endl;

}
