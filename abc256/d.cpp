#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {


  ll N; cin >> N;
  vector<pair<ll,ll>> LR(N);
  for(ll i=0;i<N;i++){
    pair<ll,ll> p;
    cin >> p.first;
    cin >> p.second;
    LR[i]=p;
  }

  sort(LR.begin(),LR.end());

  pair<ll,ll> currentLR;
  currentLR = LR[0];
  // bool flag;
  for(ll i=1;i<N;i++){
    pair<ll,ll> nextLR = LR[i];
    // flag=false;
    if(currentLR.second<nextLR.first){
      cout << currentLR.first << " " << currentLR.second << endl;
      currentLR = nextLR;
      // flag=true;
    }
    else if(currentLR.second <= nextLR.second){
      currentLR.second = nextLR.second;
    }else{

    }
  }
  // if(!flag) 
      cout << currentLR.first << " " << currentLR.second << endl;
  return 0;
}