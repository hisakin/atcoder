#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;

//cでもc++でも
ll gcd(ll a, ll b){
  if(a%b == 0){
    return b;
  }else{
    return gcd(b, a%b);
  }
}

int main(int argc, const char * argv[]) {

  ll N;cin >> N;
  vector<pair<ll,ll>> pos(N);
  for(ll i=0;i<N;i++){
    ll x,y;
    cin >> x >> y;
    pos[i].first = x;
    pos[i].second = y;
  }

  map<pair<ll,ll>,ll> m;
  ll ans=0;

  for(ll i=0;i<N;i++){
    for(ll j=i+1;j<N;j++){
      ll a = pos[i].first - pos[j].first;
      ll b = pos[i].second - pos[j].second;
      //aを正の値で固定する
      if(a<0){
        a = -a;
        b = -b;
      }
      // cout << "a:" << a << ", b:" << b << endl;
      pair<ll,ll> p1;
      pair<ll,ll> p2;;
      if(a==0){
        p1 = {0,1};
        p2 = {0,-1};
      }
      else if(b==0){
        p1 = {1,0};
        p2 = {-1,0};
      }else{
      ll gcdnum = gcd(a,b);
      p1 = {a/gcdnum,b/gcdnum};
      p2 = {-(a/gcdnum),-(b/gcdnum)};
      }

      //keyがない場合
      if(m.find(p1) == m.end()){
        m[p1]=1;
        ans++;
      }
      if(m.find(p2) == m.end()){
        m[p2]=1;
        ans++;
      }

    }
  }
  cout << ans << endl;
  return 0;
}