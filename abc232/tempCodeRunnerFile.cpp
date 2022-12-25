#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;

ll N,M;

int main(int argc, const char * argv[]) {

  cin >> N >> M;
  Graph Gt(N),Ga(N);
  for(ll i=0;i<M;i++){
    ll a,b; cin >> a >> b;
    a--; b--;
    Gt[a].push_back(b);
    Gt[b].push_back(a);
  }
  for(ll i=0;i<M;i++){
    ll a,b; cin >> a >> b;
    a--; b--;
    Ga[a].push_back(b);
    Ga[b].push_back(a);
  }
  for(ll i=0;i<N;i++){
    sort(Gt[i].begin(),Gt[i].end());
  }

  vector<int> nums(N);
  iota(nums.begin(), nums.end(), 0);
  bool ans=true;
  do {
      ans=true;
      for(ll i=0;i<nums.size();i++){
        if(Gt[i].size()!=Ga[nums[i]].size()){
          ans=false;
          break;
        }
        vector<ll> temp(Gt[i].size());
        for(ll k=0;k<Gt[i].size();k++){
          temp[k] = nums[Ga[nums[i]][k]];
        }

        sort(temp.begin(),temp.end());

        for(ll j=0;j<Gt[i].size();j++){
          if(Gt[i][j]!=temp[j]){
            ans=false;
            break;
          }
        }
      }
      if(ans){
        break;
      }
  } while (next_permutation(nums.begin(), nums.end()));

  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}