#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {


    ll N; cin >> N;
    vector<string> S(N);
    vector<vector<ll>> cnt(10,vector<ll>(10,0));



    //入力受取り
    for(ll i=0;i<N; i++){
      cin >> S[i];
    }
  //cnt配列の作成
  for(ll k=0; k<10;k++){
    for(ll j=0;j<10;j++){
      for(ll i=0;i<N;i++){
        if(k==S[i][j]-'0'){
          cnt[k][j]++;
        }     
      }
    }
  }
  ll min = N+1;
  ll min_j=10, min_k;
  ll max_cnt = 0;
  ll max_j;




  for(ll k=0;k<10;k++){
    max_cnt = 0;
    //kの場合の最大のcnt値、その時のjを取得(同じcnt値の場合はjはより後ろの値とする)
    for(ll j=0;j<10;j++){
      if(max_cnt<=cnt[k][j]){
        max_cnt = cnt[k][j];
        max_j = j;
      }
    }
    if(min > max_cnt || (min==max_cnt && min_j > max_j)){
      min = max_cnt;
      min_j = max_j;
      min_k = k;
    }
  }

  ll ans = min_j + 10*(min-1);
  cout << ans << endl;

}