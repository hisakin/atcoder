#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;


int main(int argc, const char * argv[]) {

  ll X,Y,N; cin >> N >> X >> Y;
  vector<ll> A(N+1);
  ll const MAXNUM = 2*10000 + 1;
  ll const OFFSET = 10000;

  vector<vector<ll>> MEMO_X(N+2,vector<ll>(MAXNUM,-1));
  vector<vector<ll>> MEMO_Y(N+2,vector<ll>(MAXNUM,-1));

  for(ll i=1;i<=N;i++) cin >> A[i];
  for(ll j=0;j<MAXNUM;j++) MEMO_X[2][j]=0;
  for(ll j=0;j<MAXNUM;j++) MEMO_Y[2][j]=0;
  MEMO_X[2][A[1]+OFFSET]=1;
  MEMO_Y[2][0+OFFSET]=1;

  for(ll i=3;i<=N+1;i++){
    if(i%2==1){
      for(ll k=0;k<MAXNUM;k++){
        MEMO_X[i][k]=MEMO_X[i-1][k];
      }
    }
    if(i%2==0){
      for(ll k=0;k<MAXNUM;k++){
        if(MEMO_X[i-1][k]==1){
          MEMO_X[i][k+A[i-1]]=1;
          MEMO_X[i][k-A[i-1]]=1;
        }
      }      
    }
    // for(ll k=0;k<MAXNUM;k++){
    //   if(MEMO_X[i][k]==-1) MEMO_X[i][k]=0; 
    // }

  }

  for(ll i=3;i<=N+1;i++){
    if(i%2==0){
      for(ll k=0;k<MAXNUM;k++){
        MEMO_Y[i][k]=MEMO_Y[i-1][k];
      }
    }
    if(i%2==1){
      for(ll k=0;k<MAXNUM;k++){
        if(MEMO_Y[i-1][k]==1){
          MEMO_Y[i][k+A[i-1]]=1;
          MEMO_Y[i][k-A[i-1]]=1;
        }
      }      
    }
    // for(ll k=0;k<MAXNUM;k++){
    //   if(MEMO_Y[i][k]==-1) MEMO_Y[i][k]=0; 
    // }
  }

  // cout << "MEMO_X[N+1][X+OFFSET]:" << MEMO_X[N+1][X+OFFSET] << endl;
  // cout << "MEMO_Y[N+1][Y+OFFSET]:" << MEMO_Y[N+1][Y+OFFSET] << endl;

  if(MEMO_X[N+1][X+OFFSET]==1 && MEMO_Y[N+1][Y+OFFSET]==1) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}