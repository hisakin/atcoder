#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;

ll N,S;
vector<ll> A;
vector<ll> B;

vector<ll> ANSLIST; 
bool flag=false;

vector<vector<ll>> MEMO;

bool f(ll n,ll sum, vector<ll> &combi){
  // cout << "n:" << n << ", sum:" << sum << endl;
  if(flag) return true;
  if(sum<0) return false;
  if(MEMO[n][sum]==0) return false;
  if(n!=1 && MEMO[n][sum]==1) return true; 
  if(n==1 && MEMO[n][sum]==1){
    if(A[1]==sum){
      // cout << "ここA" << endl;
      //記録処理
      combi.push_back(0);
      for(ll i=0;i<N;i++){
        ANSLIST[i]=combi[i];
        // cout << ANSLIST[i];
      }
    }
    else if(B[1]==sum){
      // cout << "ここB" << endl;
      //記録処理
      combi.push_back(1);
      for(ll i=0;i<N;i++){
        ANSLIST[i]=combi[i];
        // cout << ANSLIST[i];
      }
    }
    flag=true;
    return true;
  }
  combi.push_back(0);
  bool ret1 = f(n-1,sum-A[n],combi);
  if(ret1) MEMO[n-1][sum-A[n]]=1;
  else if(sum-A[n]>=0) MEMO[n-1][sum-A[n]]=0;
  combi.pop_back();

  combi.push_back(1);
  bool ret2 = f(n-1,sum-B[n],combi);
  if(ret2) MEMO[n-1][sum-B[n]]=1;
  else if(sum-B[n]>=0) MEMO[n-1][sum-B[n]]=0;
  combi.pop_back();

  return ret1 | ret2;

}

int main(int argc, const char * argv[]) {

  cin >> N >> S;
  A = vector<ll>(N+1); 
  B = vector<ll>(N+1); 
  ANSLIST = vector<ll> (N);
  for(ll i=1;i<N+1;i++){
    cin >> A[i] >> B[i];
  }
  A[0]=0;
  B[0]=0;

  for(ll i=1;i<N+1;i++){
    // cout << "A[" << i << "]=" << B[i]<< " ";
  }cout << endl;

  //メモ化再帰 定義&初期化処理
  MEMO = vector<vector<ll>>(N+1,vector<ll>(S+1,-1));

  for(ll i=0;i<S+1;i++){
    MEMO[0][i]=0;
    MEMO[1][i]=0;
  }
  MEMO[1][A[1]]=1;
  MEMO[1][B[1]]=1;
  for(ll i=0;i<N+1;i++){
    MEMO[i][0]=0;
  }

  vector<ll> combi;
  bool ans = f(N,S,combi);

  if(ans){
    cout << "Yes" << endl;
    for(ll i=N-1;i>=0;i--){
      if(ANSLIST[i]==0) cout << "H";
      else cout << "T";
    }
    cout << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}