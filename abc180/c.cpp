#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long

set<long long> yakusu_list(long long N){
  set<long long> ret;
  for(long long i=1;i*i<=N;i++){
    if(N%i!= 0) continue;
    ret.insert(i);
    ret.insert(N/i);
  }

  return ret;
}
int main(int argc, const char * argv[]) {

  ll N; cin >> N;
  auto ret = yakusu_list(N);

  for(auto it = ret.begin(); it!=ret.end();it++){
    cout << *it << endl;
  }

}