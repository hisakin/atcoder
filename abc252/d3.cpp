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

  sort(A.begin(),A.end());

  vector<ll> CNT(2*100000+1,0);
  vector<ll> SUM(2*100000+1,0);//部分和

  for(ll j=0;j<N;j++){
    CNT[A[j]]++; //各数字が何回あるのか、カウント
  }

  SUM[0]=0;
  for(ll j=1;j<2*100000+1;j++){
    SUM[j]= SUM[j-1]+CNT[j];
  }

  ll ans=0;
  // for(ll j=1;j<200000;j++){
  //   if(CNT[j]==0) continue;
  //   ans += SUM[j-1]*(SUM[200000]-SUM[j]);
  // }

  for(ll j=1;j<N-1;j++){
    ans += SUM[A[j]-1]*(SUM[200000]-SUM[A[j]]);
  }

  // for(ll i=0;i<15;i++){
  //   cout << "CNT[" << i << "]=" << CNT[i];
  //   cout << "   SUM[" << i << "]=" << SUM[i] << endl;
  // }

  cout << ans << endl;



}