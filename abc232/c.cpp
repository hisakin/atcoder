#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;

ll N,M;
void printVector(const vector<int>& vec) {
    cout << "[";
    for (int value : vec) {
        cout <<  value << " ";
    }
    cout << "]" << endl;
}

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
  // cout << "ソート確認" << endl;
  for(ll i=0;i<N;i++){
    // cout << "i:" << i << endl;
    // for(ll k=0;k<Gt[i].size();k++){
    //   cout << Gt[i][k] << " ";
    // }
    // cout << endl;
    sort(Gt[i].begin(),Gt[i].end());
  }
  // cout << "ソート確認終了" << endl;


    vector<int> nums(N);
    iota(nums.begin(), nums.end(), 0);
    bool ans=true;
    do {
        printVector(nums);
        ans=true;
        for(ll i=0;i<nums.size();i++){
          if(Gt[i].size()!=Ga[nums[i]].size()){
            cout << "頂点数が異なる：Gt[" << i << "].size:" << Gt[i].size() << " Ga[" << nums[i] << "]].size:" << Ga[nums[i]].size() << endl;
            ans=false;
            break;
          }
          vector<ll> temp(Gt[i].size());
          cout << "高橋:ノード" << i << "の隣接ノード  ";
          for(ll k=0;k<Gt[i].size();k++){
            cout << Gt[i][k] << " ";
          } cout << endl;


          for(ll k=0;k<Gt[i].size();k++){
            temp[k] = nums[Ga[nums[i]][k]];
          }

          sort(temp.begin(),temp.end());
          cout << "青木:ノード" << i << "の隣接ノード  ";
          for(ll k=0;k<Gt[i].size();k++){
            cout << temp[k] << " ";
          } cout << endl;

          for(ll j=0;j<Gt[i].size();j++){
            if(Gt[i][j]!=temp[j]){
              cout << "隣接ノードが異なる  i : " << i << " ,  j : " << j << "  nums[i]:" << nums[i] << "  nums[j]:" << nums[j] << endl;
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