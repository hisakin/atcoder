#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {

  ll N; cin >> N;
  vector<ll> P(N);
  for(ll i=0;i<N;i++) cin >> P[i];

  ll index=N-1;
  ll p;
  for(ll i=N-1;i>0;i--){
    if(P[i]<P[i-1]){
      index=i-1;
      p=P[index];
      break;
    }
  }

  // cout << "index:" << index << endl;

  set<ll> exist;

  for(ll i=0;i<index;i++){
    exist.insert(P[i]);
  }

  vector<ll> ans;
  for(ll i=0;i<index;i++){
    ans.push_back(P[i]);
  }

  for(ll i=index;i<N;i++){

    // cout << "i=" << i << endl;
    // for(ll k=0;k<ans.size();k++){
    //   cout << ans[k] << " ";
    // }
    // cout << endl;

    if(i==index){
      exist.erase(p);
      for(ll j=p-1;j>=1;j--){
        if(exist.find(j) == exist.end()){
          ans.push_back(j);
          exist.insert(j);
          break;
        }
      }
      continue;
    }
    for(ll j=N;j>=1;j--){
      if(exist.find(j) == exist.end()){
        ans.push_back(j);
        exist.insert(j);
        break;
      }
    }
  }

  for(ll i=0;i<N;i++){
    cout << ans[i] << " ";
  }
  cout << endl;

  return 0;
}