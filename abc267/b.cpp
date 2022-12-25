#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long

bool check_exist(vector<ll> list){
  bool ans=false;
  for(ll i=0;i<list.size();i++){
    if(list[i]==1){
      ans=true;
      break;
    }
  }
  return ans;
}

bool check_allfalse(vector<ll> list){
  for(ll i=0;i<list.size();i++){
    if(list[i]==1) return false;
  }
  return true;
}

int main(int argc, const char * argv[]) {

  string S; cin >> S;
  vector<vector<ll>> row(7,vector<ll>());

  if(S[0]-48==1){
    cout << "No" << endl;
    return 0;
  }

  row[0].push_back(S[6]-48);
  row[1].push_back(S[3]-48);
  row[2].push_back(S[1]-48);
  row[2].push_back(S[7]-48);
  row[3].push_back(S[0]-48);
  row[3].push_back(S[4]-48);
  row[4].push_back(S[2]-48);
  row[4].push_back(S[8]-48);
  row[5].push_back(S[5]-48);
  row[6].push_back(S[9]-48);

  bool ans=false;
  bool flag=false;

  for(ll i=0;i<7;i++){
    for(ll j=i+1;j<7;j++){
      if( !check_exist(row[i]) || !check_exist(row[j])  )
        continue;
      for(ll k=i+1;k<j;k++){
        if(check_allfalse(row[k])){
          ans=true;
          flag=true;
          break;
        }
      }
      if(flag)break;
    }
    if(flag)break;
  }
  if(ans)  cout << "Yes" << endl;
  else cout << "No" << endl;









  return 0;
}