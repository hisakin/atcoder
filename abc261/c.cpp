#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {


  ll N; cin >> N;
  vector<string> S(N);
  for(ll i=0;i<N;i++){
    cin >> S[i];
  }

  map<string,ll> MAP;
  for(ll i=0;i<N;i++){
    if(MAP[S[i]]==0){
      cout << S[i] << endl;
    }
    else{
      cout << S[i] << "(" << MAP[S[i]] << ")" << endl;
    }
    MAP[S[i]]++;
  }

  return 0;
}