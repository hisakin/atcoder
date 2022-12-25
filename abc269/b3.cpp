#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {


  vector<string> S(10);
  for(ll i=0;i<10;i++){
    cin >> S[i];
  }

  ll N=10;
  bool flag=false;
  ll A,B,C,D;
  for(ll i=0;i<N;i++){
    for(ll j=0;j<N;j++){
      if(S[i][j]=='.') continue;
      A=i; C=j;
      flag=true;
      break;
    }
    if(flag) break;
  }


  flag=false;
  for(ll i=N-1;i>=0;i--){
    for(ll j=N-1;j>=0;j--){
      if(S[i][j]=='.') continue;
      B=i; D=j;
      flag=true;
      break;
    }
    if(flag) break;
  }
  A++;
  B++;
  C++;
  D++;

  cout << A <<  " " << B << endl;
  cout << C <<  " " << D << endl;
  return 0;
}