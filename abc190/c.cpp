#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;

ll N,M,K;
vector<pair<ll,ll>> condition;
vector<pair<ll,ll>> pattern;
ll ans=0;
void dfs(vector<ll> &list,ll depth){
  if(list.size()==K){
    // cout << "listを表示" << endl;
    // for(ll i=0;i<list.size();i++){
    //   cout << list[i] << " ";
    // }
    // cout << endl;
    ll cnt=0;
    for(ll i=0;i<M;i++){
      if( find(list.begin(),list.end(),condition[i].first)!=list.end() && 
          find(list.begin(),list.end(),condition[i].second)!=list.end()){
            cnt++;
      }
    }
    ans = max(ans,cnt);
    return;
  }
  list.push_back(pattern[depth].first);
  dfs(list,depth+1);
  list.pop_back();

  list.push_back(pattern[depth].second);
  dfs(list,depth+1);
  list.pop_back();
}

int main(int argc, const char * argv[]) {
  cin >> N >> M;
  condition = vector<pair<ll,ll>>(M);
  for(ll i=0;i<M;i++){
    pair<ll,ll> p;
    cin >> p.first >> p.second;
    p.first--; p.second--;
    condition[i]=p;
  }
  cin >> K;
  pattern = vector<pair<ll,ll>>(K);
  for(ll i=0;i<K;i++){
    pair<ll,ll> p;
    cin >> p.first >> p.second;
    p.first--; p.second--;
    pattern[i]=p;
  }

  vector<ll> X; dfs(X,0);
  cout << ans << endl;

  return 0;
}