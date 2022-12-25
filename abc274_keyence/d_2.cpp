#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;

struct pos{
  ll n;
  ll x;
  ll y;

  bool operator < (const pos& rhs ) const {
    if (n < rhs.n) { 
      return true; 
    } 
    if (n > rhs.n) {
      return false;
    }
    if (x < rhs.x) { 
      return true; 
    } 
    if (x > rhs.x) {
      return false;
    }
    if (y < rhs.y) { 
      return true; 
    } 
    if (y > rhs.y) {
      return false;
    }
    return false;
  }
};

ll X,Y,N; 
vector<ll> A;
map<pos,ll> m;


bool dp(ll n, ll x, ll y){
  // cout << "n:" << n << " x:" << x << " y:" << y << endl;
  if(n==2){
    if(x==A[1] && y==0){
      return true;
    }else{
      return false;
    }
  }

  pos s = {n,x,y};
  if(m[s]==1){
    return true;
  }
  if(m[s]==2){
    return false;
  }

  bool ret;
  if(n%2==0){
    ret = dp(n-1,x+A[n-1],y) || dp(n-1,x-A[n-1],y);
  }else{
    ret = dp(n-1,x,y+A[n-1]) || dp(n-1,x,y-A[n-1]);
  }
  // cout << "ret:" << ret << endl;
  if(ret) m[s]=1;
  else m[s]=2;

  return ret;
}

int main(int argc, const char * argv[]) {

  cin >> N;
  cin >> X >> Y;
  A = vector<ll>(N+1);
  for(ll i=1;i<=N;i++) cin >> A[i];
  bool ans = dp(N+1,X,Y);

  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}