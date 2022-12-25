#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long

vector<vector<ll>> Pattern;

void dfs(ll N, vector<ll> p){
  if(p.size()==N){
    Pattern.push_back(p);
    return ;
  }
  p.push_back(0);
  dfs(N,p);
  p.pop_back();
  p.push_back(1);
  dfs(N,p);
  p.pop_back();
}

bool check(vector<vector<ll>> A, vector<vector<ll>> B){
  for(ll i=0;i<A.size();i++){
    for(ll j=0;j<A[i].size();j++){
      if(A[i][j]!=B[i][j]){
        return false;
      }
    }
  }
  return true;
}

int main(int argc, const char * argv[]) {

  ll H1,W1; cin >> H1 >> W1;
  vector<vector<ll>> A(H1,vector<ll>(W1));
  for(ll i=0;i<H1;i++){
    for(ll j=0;j<W1;j++){
      cin >> A[i][j];
    }
  }
  ll H2,W2; cin >> H2 >> W2;
  vector<vector<ll>> B(H2,vector<ll>(W2));
  for(ll i=0;i<H2;i++){
    for(ll j=0;j<W2;j++){
      cin >> B[i][j];
    }
  }

  vector<ll> p; dfs(H1+W1,p);

  bool ans=false;

  for(ll i=0;i<Pattern.size();i++){

    //Pattern[i]に対し、比較しやすいように、行成分と列成分を抽出
    vector<ll> temp = Pattern[i];
    vector<ll> temp_H1(H1), temp_W1(W1);

    for(ll j=0;j<H1; j++) temp_H1[j]=temp[j];
    for(ll j=0;j<W1; j++) temp_W1[j]=temp[j+H1];

    //Aから行・列を除いたものとBのサイズが一致するか否かのチェック
    ll sum=0;
    for(ll j=0;j<H1;j++){
      if(temp_H1[j]==1) sum++;
    }
    if(sum!=H2) continue;

    sum=0;
    for(ll j=0;j<W1;j++){
      if(temp_W1[j]==1) sum++;
    }
    if(sum!=W2) continue;

    //Bとサイズが一致する候補の行列を作成しA_newに代入
    vector<vector<ll>> A_new(H2,vector<ll>(W2));
    ll A_new_index_H2=0, A_new_index_W2=0;

    for(ll j=0;j<H1;j++){
      for(ll k=0;k<W1;k++){
        if(temp_H1[j]==1 && temp_W1[k]==1){
          A_new[A_new_index_H2][A_new_index_W2] = A[j][k];
          A_new_index_W2 = (A_new_index_W2+1)%W2;
          if(A_new_index_W2==0) A_new_index_H2++; 
          continue;
        }
      }
    }
    //A_newとBが一致するか否かをチェック
    if(check(A_new,B)){
      ans=true;
      break;
    }
  }

  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}