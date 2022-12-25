#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {


  deque<ll> deq_kind;
  deque<ll> deq_num;
  
  ll Q; cin >> Q;
  vector<vector<ll>> query(Q);
  for(ll i=0;i<Q;i++){
    ll kind; cin >> kind;
    query[i].push_back(kind);
    if(kind==1){
      for(ll j=0;j<2;j++){
        ll input; cin >> input;
        query[i].push_back(input);
      }
    }
    else{
      ll input; cin >> input;
      query[i].push_back(input);
    }
  }

  for(ll i=0;i<Q;i++){
    if(query[i][0]==2) continue;
    if(deq_kind.front()==query[i][1]){ //ランレングス符号化を行う場合
      ll temp_num = deq_num.front();
      deq_num.pop_front();
      deq_num.push_front(temp_num+query[i][2]);
    }
    else{ //ランレングス符号化を行わない場合
      deq_num.push_front(query[i][2]);
      deq_kind.push_front(query[i][1]);
    }
  }

  for(ll i=0;i<Q;i++){
    if(query[i][0]==1) continue;
    ll cnt = query[i][1];
    ll ans = 0;
    while(true){
      ll tempcnt = deq_num.back();
      if(tempcnt < cnt){//足りない場合
        ans += tempcnt * deq_kind.back();
        cnt -= tempcnt;
        deq_num.pop_back();
        deq_kind.pop_back();
        continue;
      }
      else if (tempcnt == cnt){//ちょうど足りる場合
        ans += cnt * deq_kind.back();
        deq_num.pop_back();
        deq_kind.pop_back();
        break;
      }
      else{//余る場合
        ll kind = deq_kind.back();
        ll num = deq_num.back(); deq_num.pop_back();
        deq_num.push_back(tempcnt-cnt);
        ans += cnt * kind;
        break;
      }
    }
    cout << ans << endl;
  }







  return 0;
}