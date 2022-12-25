#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {


  string S; cin >> S;
  unsigned ll K; cin >> K;
  vector<ll> NUM(S.size());
  for(ll i=0;i<S.size();i++){
    NUM[i] = S[S.size()-i-1] - '0';
    // cout << NUM[i] << " ";
  }
  // cout << endl;

  NUM.push_back(0);

  for(ll i=0;i<K;i++){
    if(NUM.size()==i) break;
    if(NUM[i]>=5){
      // cout << "ここ" << endl;
      NUM[i+1]++;
      NUM[i]=0;
    }else{
      // cout << "ここ2" << endl;
      NUM[i]=0;
    }
  }

  ll index=1;
  ll ans=0;
  for(ll i=0;i<NUM.size();i++){
    ans += NUM[i]*index;
    index=index*10;
  }

  cout << ans << endl;


  // cout << "答え" << endl;
  // for(ll i=0;i<NUM.size();i++){
  //   cout << NUM[i] << " ";
  // }
  // cout << endl;



  return 0;
}