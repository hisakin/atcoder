#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;

ll N,W;
vector<ll> WEIGHT, VALUE;

int main(int argc, const char * argv[]) {

  cin >> N >> W;
  WEIGHT = vector<ll>(N+1);
  VALUE = vector<ll>(N+1);
  for(ll i=1;i<=N;i++){
    cin >> WEIGHT[i] >> VALUE[i];
  }

  






  return 0;
}