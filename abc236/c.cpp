#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
#define rep(i,N) for(ll i=0;i<(N);i++)

int main(int argc, const char * argv[]) {

  ll N,M; cin >> N >> M;
  vector<string> S(N),T(M);
  rep(i,N) cin >> S[i];
  rep(i,M) cin >> T[i];

  ll t_index = 0;
  for(ll i=0;i<N;i++){
    string kyuko = T[t_index];
    if(kyuko.compare(S[i])==0){
      //一致していた場合
      cout << "Yes" << endl;   
      t_index++;   
    }else{
      cout << "No" << endl;
    }
  }





  return 0;
}