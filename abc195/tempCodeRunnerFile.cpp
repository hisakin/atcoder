#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {

  ll A,B,W; cin >> A >> B >> W;
  W = 1000 * W;
  ll min_ans = -1;
  ll max_ans = -1;
  for(ll i=1;i<=1000000;i++){
    ll left = A * i;
    ll right = B * i;
    if(left<=W && W<=right && min_ans!=-1){
      max_ans++;
    }
    if(left<=W && W<=right && min_ans==-1){
      min_ans=i;
      max_ans=i;
    }
    
  }
  if(min_ans==-1 || max_ans==-1){
    cout << "UNSATISFIABLE" << endl;
  }
  else{
    cout << min_ans << " " << max_ans << endl;
  }
  return 0;
}