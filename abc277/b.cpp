#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {

  ll N; cin >> N;
  vector<string> S(N);
  for(ll i=0;i<N;i++){
    cin >> S[i];
  }
  string A = {'H','D','C','S'};
  string B = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};

  bool Aflag=true;
  for(ll i=0;i<N;i++){
    bool Atempflag=false;
    for(ll j=0;j<A.size();j++){
      if(S[i][0]==A[j]){
        Atempflag=true;
      }
    }
    if(!Atempflag){
      Aflag=false;
      break;
    }
  }
  bool Bflag=true;
  for(ll i=0;i<N;i++){
    bool Btempflag=false;
    for(ll j=0;j<B.size();j++){
      if(S[i][1]==B[j]){
        Btempflag=true;
      }
    }
    if(!Btempflag){
      Bflag=false;
      break;
    }
  }

  bool Cflag=true;
  for(ll i=0;i<N;i++){
    for(ll j=i+1;j<N;j++){
      if(S[i]==S[j]){
        Cflag=false;
        break;
      }
    }
  }

  if(Aflag&&Bflag&&Cflag){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }

  // cout << Aflag << " " << Bflag << " " << Cflag << endl;

  return 0;
}