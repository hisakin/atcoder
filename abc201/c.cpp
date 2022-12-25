#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
vector<ll> list_maru;
vector<ll> list_batu;
vector<ll> list_hatena;
vector<ll> list_maruorhatena;

ll ans=0;

void dfs(vector<ll> &list){
  if(list.size()==4){
    //●含んでいるか確認
    bool isok=true;
    for(ll j=0;j<list_maru.size();j++){
      if(find(list.begin(),list.end(),list_maru[j])==list.end()){
        isok = false;
        break;
      }
    }
    if(isok){
      ans++;
    }
    return;
  }
  for(ll i=0;i<list_maruorhatena.size();i++){
    list.push_back(list_maruorhatena[i]);
    dfs(list);
    list.pop_back();
  }
}

int main(int argc, const char * argv[]) {


  string S; cin >> S;
  for(ll i=0;i<S.size();i++){
    if(S[i]=='o'){
      list_maru.push_back(i);
      list_maruorhatena.push_back(i);
    }
    if(S[i]=='x'){
      list_batu.push_back(i);
    }
    if(S[i]=='?'){
      list_hatena.push_back(i);
      list_maruorhatena.push_back(i);
    }
  }

  vector<ll> X;
  dfs(X);

  cout << ans << endl;

  return 0;
}