#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long

ll N,M;
void dfs(vector<ll> A){
  if(A.size()==N){
    for(ll i=0;i<A.size();i++){
      cout << A[i] << " ";
    }
    cout << endl;
  }

  for(ll i=A.back()+1;i<=M;i++){
    A.push_back(i);
    dfs(A);
    A.pop_back();
  }
}

int main(int argc, const char * argv[]) {

  cin >> N >> M;

  for(ll i=1;i<=M; i++){
    dfs(vector<ll>{i});
  }

  return 0;
}