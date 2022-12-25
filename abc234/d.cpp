#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {

  ll N,K; cin >> N >> K;
  vector<ll> P(N);
  for(ll i=0;i<N;i++) cin >> P[i];

  std::priority_queue<
  ll,                // 要素の型はll
  std::vector<ll>,   // 内部コンテナはstd::vector (デフォルトのまま)
  std::greater<ll>   // 昇順 (デフォルトはstd::less<T>)
  > que;

  for(ll i=0;i<K;i++){
    que.push(P[i]);
  }

  cout << que.top() << endl;


  for(ll i=K;i<N;i++){
    // cout << "i:" << i << "  P[" << i << "]:" << P[i] << "  que.top():" << que.top() << endl;
    if(P[i]<que.top()){
      // cout << "if" << endl;
      cout << que.top() << endl;
    }
    else{
      // cout << "else" << endl;
      que.pop();
      que.push(P[i]);
      cout << que.top() << endl;
      // cout << que.size() << endl;
    }

  }

  return 0;
}