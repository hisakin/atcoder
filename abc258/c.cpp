#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {

  ll N,Q; cin >> N >> Q;
  vector<char> S(N);
  for(ll i=0;i<N; i++){
    cin >> S[i];
  }

  vector<ll> query_type(Q);
  vector<ll> query_target(Q);

  for(ll i=0;i<Q;i++){
    cin >> query_type[i] >> query_target[i];
  }
  ll head = 0;
  ll tail = N-1;
  for(ll i=0;i<Q;i++){
    if(query_type[i]==1){
      head = (head - query_target[i] + N) % N;
      tail = (tail - query_target[i] + N) % N;
    }else{
      cout << S[(query_target[i]-1+head+N)%N] << endl;
    }
  }

}