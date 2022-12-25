#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long

ll N;

int ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}

vector<string> S(N);

ll dfs(ll target, vector<vector<bool>> searched, ll time, ll current_t){

  bool check=false;
  for(ll i=0;i<N;i++){
    if(searched[i][target]==false){
      check=true;
      break;
    }
  }
  //探索終了条件：全て探索済みの場合
  if(check==false){
    return time;
  }

  //current_tに、targetがあるかどうかを確認
  stack<ll> next_pattern;
  for(ll i=0;i<N;i++){
    if(searched[i][target])continue; //探索済のものはスルー
    if(S[i][current_t]==ctoi(target)){
      searched
      dfs(target, )

    }


  }


}

int main(int argc, const char * argv[]) {


  cin >> N;

  for(ll i=0;i<N;i++){
    cin  >>  S[i];
  }


  ll min = 1000000000;
  for(ll target=0;target<10; target++){
    vector<vector<bool>> searched(N,vector<bool>(10),false);
    ll time=0;
    ll current_t=0;
    ll min_i = dfs(target,searched,time,current_t);

    if(min > min_i){
      min = min_i;
    }

  }




}