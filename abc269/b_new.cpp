#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {


 ll N=10;
  vector<string> S(N);
  for(ll i=0;i<N;i++){
    cin >> S[i];
  }

  ll A=-1,B=-1,C=-1,D=-1;
  bool flag=false;

  for(ll i=0;i<N;i++){
    for(ll j=0;j<N;j++){
      if(S[i][j]=='#'){
        A=i; 
        C=j;
        flag=true;
        break;
      }
    }
    if(flag) break;
  }

  B=A;
  D=C;

  for(ll i=1;i+C<N;i++){
    if(S[A][C+i]=='#'){
      D++;
    }else{
      break;
    }
  }
  for(ll i=1;i+A<N;i++){
    if(S[i+A][C]=='#'){
      B++;
    }else{
      break;
    }
  }

  cout << A+1 << ' ' << B+1 << endl;
  cout << C+1 << ' ' << D+1 << endl;


  return 0;
}