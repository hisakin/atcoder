#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {

  ll N; cin >> N;
  string S; cin >> S;
  ll Q; cin >> Q;
  vector<ll> T(Q),A(Q),B(Q);
  for(ll i=0;i<Q;i++){
    cin >> T[i] >> A[i] >> B[i];
    A[i]--; B[i]--;
  }

  vector<char> front(N),back(N);
  for(ll i=0;i<N;i++) front[i]=S[i];
  for(ll i=0;i<N;i++) back[i]=S[i+N];

  for(ll i=0;i<Q;i++){
    if(T[i]==1){
      if(A[i]<N && B[i]>=N){
        swap(front[A[i]],back[B[i]-N]);
      }else if(A[i]>=N){
        swap(back[A[i]-N],back[B[i]-N]);
      }else{
        swap(front[A[i]],front[B[i]]);
      }
    }else{
      swap(front,back);
    }
  }

  for(ll i=0;i<2*N;i++){
    if(i<N){
      cout << front[i];
    }else{
      cout << back[i-N];
    }
  }
  return 0;
}