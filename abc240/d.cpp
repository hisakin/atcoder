#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;

struct BALL{
  ll kind;
  ll num;
};

int main(int argc, const char * argv[]) {

  ll N; cin >> N;
  vector<ll> A(N);
  for(ll i=0;i<N;i++) cin >> A[i];

  stack<BALL> BALLstack;
  BALL initial_ball = {A[0],1};
  BALLstack.push(initial_ball);
  ll cnt = 1;
  cout << cnt << endl;
  for(ll i=1;i<N;i++){

    if(BALLstack.empty()){
      BALL new_ball = {A[i],1};
      BALLstack.push(new_ball);      
      cnt++;
      cout << cnt << endl;
      continue;
    }

    BALL top_ball = BALLstack.top();
    if(A[i]==top_ball.kind && top_ball.num+1==top_ball.kind){
      BALLstack.pop();
      cnt -= top_ball.num;
    }
    else if(A[i]==top_ball.kind){
      BALLstack.pop();
      top_ball.num++;
      BALLstack.push(top_ball);
      cnt++;
    }
    else{
      BALL new_ball = {A[i],1};
      BALLstack.push(new_ball);
      cnt++;
    }
    cout << cnt << endl;
  }

  return 0;
}