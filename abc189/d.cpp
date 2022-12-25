#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll unsigned long long
using Graph = vector<vector<ll>>;

vector<ll> POW2LIST(62);

int main(int argc, const char * argv[]) {

  ll N; cin >> N;
  vector<string> S(N);
  for(ll i=0;i<N;i++) cin >> S[i];

  POW2LIST[0]=1;
  for(ll i=1;i<=61;i++){
    POW2LIST[i]=POW2LIST[i-1]*2;
  }

  ll sum;
  if(S[0]=="AND"){
    sum=1;
  }else{
    sum=3;
  }

  for(ll i=1;i<N;i++){
    // cout << "sum:" << sum << endl;
    // cout << "POW2LIST[" << i+1 << "]:" << POW2LIST[i+1] << endl;

    if(S[i]=="AND"){

    }else{
      sum = sum + POW2LIST[i+1];
    }
  }

  cout << sum << endl;
  return 0;
}