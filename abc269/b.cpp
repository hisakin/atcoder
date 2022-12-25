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

  ll A,B,C,D;
  for(ll i=0;i<N;i++){
    if(S[i].compare("..........")==0){
      continue;
    }
    A=i;
    break;
  }

  for(ll i=A;i<N;i++){
    if(S[i].compare("..........")!=0){
      continue;
    }
    B=i;
    break;
  }

  for(ll i=0;i<N;i++){
    if(S[0][i]=='.' && 
       S[1][i]=='.' &&
       S[2][i]=='.' &&
       S[3][i]=='.' &&
       S[4][i]=='.' &&
       S[5][i]=='.' &&
       S[6][i]=='.' &&
       S[7][i]=='.' &&
       S[8][i]=='.' &&
       S[9][i]=='.'){
      continue;
    }
    C=i;
    break;
  }
  for(ll i=C;i<N;i++){
    for(ll j=A;j<=B;j++){
      if (S[j][i]=='.'){
        D=i;
        break;
      }
    }
  }

  cout << A+1 << ' ' << B+1 << endl;
  cout << C+1 << ' ' << D+1 << endl;

  return 0;
}