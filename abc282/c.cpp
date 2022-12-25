#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {

  ll N; cin >> N;
  string S; cin >> S;
  string ANS;
  ll cnt=0;

  for(ll i=0;i<N;i++){
    if(cnt==0){
      if(S[i]=='"'){
        cnt++; cnt %= 2;
        ANS.push_back('"');
      }
      else if(S[i]==','){
        ANS.push_back('.');
      }
      else{
        ANS.push_back(S[i]);
      }
    }else{
      if(S[i]=='"'){
        cnt++; cnt %= 2;
        ANS.push_back('"');
      }
      else{
        ANS.push_back(S[i]);
      }
    }
  }
  cout << ANS << endl;
  return 0;
}