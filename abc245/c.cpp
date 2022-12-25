#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;

vector<vector<ll>> MEMO;
vector<ll> A;
vector<ll> B;
ll K;
bool dp(ll n, ll kind){
  if(MEMO[n][kind]!=-1){
    return MEMO[n][kind];
  }

  bool result_a, result_b;
  if(kind==0){
    result_a = dp(n-1,0) && (abs(A[n]-A[n-1])<=K);
    result_b = dp(n-1,1) && (abs(A[n]-B[n-1])<=K);
  }else{
    result_a = dp(n-1,0) && (abs(B[n]-A[n-1])<=K);
    result_b = dp(n-1,1) && (abs(B[n]-B[n-1])<=K);
  }

  if(result_a || result_b){
    MEMO[n][kind]=1;
    return true;
  }else{
    MEMO[n][kind]=0;
    return false;
  }
}

int main(int argc, const char * argv[]) {

  ll N; cin >> N >> K;
  A = vector<ll>(N+1);
  B = vector<ll>(N+1);
  for(ll i=1;i<=N;i++){
    cin >> A[i];
  }
  for(ll i=1;i<=N;i++){
    cin >> B[i];
  }
  MEMO = vector<vector<ll>>(N+1,vector<ll>(2,-1));
  MEMO[1][0]=1;
  MEMO[1][1]=1;

  dp(N,0);
  dp(N,1);

  if(MEMO[N][0]==1 || MEMO[N][1]==1){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}