#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;

ll X,Y,N; 
vector<ll> A;

vector<vector<ll>> MEMO_X;
vector<vector<ll>> MEMO_Y;

bool dp_X(ll n, ll x){
  // cout << "n:" << n << " x:" << x << " y:" << y << endl;
  if(MEMO_X[n][x]!=-1){
    if(MEMO_X[n][x]==0) return false;
    else return true;
  }

  bool ret;
  if(n%2==0){
    ret = dp_X(n-1,x+A[n-1]) || dp_X(n-1,x-A[n-1]);
  }else{
    ret = dp_X(n-1,x);
  }
  if(ret) MEMO_X[n][x]=1;
  else MEMO_X[n][x]=0;

  return ret;
}
bool dp_Y(ll n, ll y){
  // cout << "n:" << n << " y:" << y << endl;
  if(MEMO_Y[n][y]!=-1){
    if(MEMO_Y[n][y]==0) return false;
    else return true;
  }

  bool ret;
  if(n%2==1){
    ret = dp_Y(n-1,y+A[n-1]) || dp_Y(n-1,y-A[n-1]);
  }else{
    ret = dp_Y(n-1,y);
  }
  if(ret) MEMO_Y[n][y]=1;
  else MEMO_Y[n][y]=0;

  return ret;
}

int main(int argc, const char * argv[]) {

  cin >> N;
  cin >> X >> Y;
  A = vector<ll>(N+1);
  ll const MAXNUM = 2*1000 + 1;
  ll const OFFSET = 1000;
  MEMO_X = vector<vector<ll>>(N+2,vector<ll>(MAXNUM,-1));
  MEMO_Y = vector<vector<ll>>(N+2,vector<ll>(MAXNUM,-1));
  for(ll i=1;i<=N;i++) cin >> A[i];
  for(ll j=0;j<MAXNUM;j++) MEMO_X[2][j]=0;
  for(ll j=0;j<MAXNUM;j++) MEMO_Y[2][j]=0;
  MEMO_X[2][A[1]+OFFSET]=1;
  MEMO_Y[2][0+OFFSET]=1;

  bool ansx = dp_X(N+1,X+OFFSET);
  bool ansy = dp_Y(N+1,Y+OFFSET);
  // return 0;

  if(ansx&&ansy) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}