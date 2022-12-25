#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bitset>
typedef long long ll;
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

const int MAX = 510000;
const int MOD = 1000000007;
const int MAX_N = 200000;

int ctoi(const char c){
 switch(c){
   case '0': return 0;
   case '1': return 1;
   case '2': return 2;
   case '3': return 3;
   case '4': return 4;
   case '5': return 5;
   case '6': return 6;
   case '7': return 7;
   case '8': return 8;
   case '9': return 9;
   default : return -1;
 }
}

struct Neighbor{
  ll node_id;
  ll edge_id;
};


vector<vector<Neighbor>> neighbor_list;
vector<ll> ans;

int main(int argc, const char * argv[]) {
  ll N; cin >> N ; neighbor_list.resize(N); ans.resize(N,-1);

  for(ll i=0;i<N-1;i++){
    ll a,b; cin >> a >> b; a--; b--;
    neighbor_list[a].push_back((Neighbor){b,i});
    neighbor_list[b].push_back((Neighbor){a,i});
  }


  ll delta = 0;
  for(ll i=0;i<N;i++){
    delta = max(delta, (ll)neighbor_list[i].size());
  }



  queue<ll> que;
  que.push(0);
  while(!que.empty()){
    ll a = que.front(); que.pop();

    vector<bool> color(delta,false);
    for(auto next_node : neighbor_list[a]){
      if(ans[next_node.edge_id] != -1 ){
        color[ans[next_node.edge_id]] = true;
      }
    }

    ll color_cnt=0;
    for(auto next_node : neighbor_list[a]){
      if(ans[next_node.edge_id] != -1)
        continue;
      
      for(;color_cnt<delta;color_cnt++){
        if(color[color_cnt]) {
          continue;
        }
        ans[next_node.edge_id]=color_cnt;
        color[color_cnt] = true;
        que.push(next_node.node_id);
        break;
      }
    }
  }

  cout << delta << endl;
  for(ll i=0; i<N-1;i++){
    cout << ans[i]+1 << endl;
  }

  return 0;
}
