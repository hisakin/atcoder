#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {

  int N,K; cin >> N >> K;
  vector<int> a(N);
  vector<vector<int>> array(K);

  for(int i=0;i<N;i++){
    cin >> a[i];
    array[i%K].push_back(a[i]);
  }

  for(ll i=0;i<K;i++){
    sort(array[i].begin(),array[i].end());
  }


  bool ans=true;
  int len = (N+K-1)/K;
  ll cnt=0;

  // for(ll i=0;i<N;i++){
  //   cout << array[i%K][i/K];
  // }
  // cout << endl;

  for(ll i=0;i<N-1;i++){
    if(array[i%K][i/K]>array[(i+1)%K][(i+1)/K]){
      ans=false;
    }
  }
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}