#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long

int main(int argc, const char * argv[]) {

  ll N; cin >> N;
  string S; cin >> S;
  ll total_child=0, total_adult=0;

  vector<ll> W(N);
  for(ll i=0;i<N;i++){
    cin >> W[i];
  }

  vector<pair<ll,ll>> P(N);

  for(ll i=0;i<N;i++){
    P[i].first = W[i];
    P[i].second = S[i] - '0';
    if(P[i].second == 1) total_adult++;
    if(P[i].second == 0) total_child++;
  }

  sort(P.begin(),P.end());

  vector<ll> sum_right_adult(N+1), sum_right_child(N+1);
  sum_right_adult[0]=total_adult;
  sum_right_child[0]=total_child;
  ll score = total_adult;

  for(ll i=0;i<N;i++){
    if( P[i].first == P[i+1].first ){
      //ひとつ前と同じ体重の場合は、iとi+1間の実数がないため、スコアは計算しない
      if(P[i].second==1){
        sum_right_child[i+1] = sum_right_child[i];
        sum_right_adult[i+1] = sum_right_adult[i]-1;
      }else{
        sum_right_child[i+1] = sum_right_child[i]-1;
        sum_right_adult[i+1] = sum_right_adult[i];
      }
      continue;
    }

    if(P[i].second == 1){
      sum_right_adult[i+1] = sum_right_adult[i] - 1;
      sum_right_child[i+1] = sum_right_child[i];
    }else{
      sum_right_adult[i+1] = sum_right_adult[i];
      sum_right_child[i+1] = sum_right_child[i] - 1;
    }
    ll temp_score = sum_right_adult[i+1] + total_child - sum_right_child[i+1];
    score = max(score,temp_score);
  }

  cout << score << endl;

}