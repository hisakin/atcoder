#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {

  string S,T; cin >> S >> T;
  vector<char> S_new;

  //0,1番目は個別にチェック
  if(S[0]!=T[0] || S[1]!=T[1]){
    cout << "No" << endl;
    return 0;
  }
  S_new.push_back(S[0]);
  S_new.push_back(S[1]);

  //2番目以降をチェック
  for(ll i=2,i_s=2 ;i<(ll)T.size();i++){
    //一致している場合は、次の要素を確認
    if(S[i_s]==T[i]){
      S_new.push_back(S[i_s]);
      i_s++;
      continue;
    }
    //一致していない場合
    //S_newの1,2要素前が同一文字でかつ同一文字追加によりT[i]と一致する場合は、S_newに追加し、次の要素を確認
    if(S_new[i-1]==S_new[i-2] && S_new[i-1]==T[i]){
      S_new.push_back(S_new[i-1]);
      continue;
    }else{
    //一致しないことが判明
      break;
    }
  }

  bool ans=true
  if(S_new.size()!=T.size()){
    ans =false;
  }else{
    for(ll i=0;i<(ll)T.size();i++){
      if(S_new[i]!=T[i]){
        ans=false;
      }
    }
  }

  if(ans){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }

  // for(ll i=0;i<S_new.size();i++){
  //   cout << S_new[i];
  // }
  // cout << endl;

  return 0;



}