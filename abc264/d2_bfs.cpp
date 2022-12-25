#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long

using Graph = vector<vector<ll>>;

string atcoder = "atcoder";
vector<string> str;
vector<ll> seen;

void dfs(string array){
  if(array.size()==7){
    str.push_back(array);
    return ;
  }

  for(auto c : atcoder){

    if(!array.empty() &&  array.find(c)!=string::npos){ 
      continue;
    }
    array.push_back(c);
    dfs(array);
    array.pop_back();
  }

}

void swap2(char *a, char *b){
  char temp = *a;
  *a = *b;
  *b = temp;
}
bool check(string A, string B){

  for(ll i=0;i<A.size()-1;i++){
    if(A[i]==B[i]) continue;
    swap2(&A[i],&A[i+1]);
    if(A.compare(B)==0){
      return true;
    }else{
      return false;
    }
  }
  return true;
}

void search(Graph G, ll s){
  ll N = (ll)G.size();
  seen = vector<ll>(N,-1);
  queue<ll> todo;

  seen[s]=0;
  todo.push(s);

  while(!todo.empty()){
    ll v = todo.front();
    todo.pop();

    for(ll x : G[v]){
      if(seen[x]!=-1) continue;
      seen[x] = seen[v] + 1;
      todo.push(x);
    }
  }
}

int main(int argc, const char * argv[]) {

  string S; cin >> S;
  string X;
  dfs(X);

  Graph G;
  for(ll i=0;i<str.size();i++){
    vector<ll> temp;
    for(ll j=0;j<str.size();j++){
      if(i==j) continue;
      if(check(str[i],str[j])){
        temp.push_back(j);
      }
    }
    G.push_back(temp);
  }

  ll s,t;
  for(ll i=0;i<str.size();i++){
    if(str[i].compare("atcoder")==0) s=i;
    if(str[i].compare(S)==0) t=i;
  }

  search(G,s);
  cout << seen[t] << endl;
  return 0;
}