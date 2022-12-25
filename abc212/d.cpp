#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {

  ll Q; cin >> Q;
  priority_queue<ll,vector<ll>,greater<ll>> pq;

  ll S=0;
  for(ll i=0;i<Q;i++){
    ll p; cin >> p;
    if(p==1){
      ll x; cin >> x;
      pq.push(x-S);
    }else if(p==2){
      ll x; cin >> x;
      S+=x;
    }else{
      ll tp = pq.top();
      tp += S;
      cout << tp << endl;
      pq.pop();
    }
  }

  return 0;
}