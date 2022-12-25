#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {

  ll N,Q; cin >> N >> Q;
  vector<ll> front(N+1,-1);
  vector<ll> back(N+1,-1);
  cout << endl;
  for(ll i=1;i<=Q;i++){
    // cout << "i:" << i << endl;
    // for(ll x=1;x<=N;x++){
    //   cout << front[x] << " ";
    // }
    // cout << endl;
    // for(ll x=1;x<=N;x++){
    //   cout << back[x] << " ";
    // }
    // cout << endl;

    ll qkind; cin >> qkind;
    ll x,y; 
    if(qkind==1){
      cin >> x >> y;
      front[y]=x;
      back[x]=y;
    }
    else if(qkind==2){
      cin >> x >> y;
      front[y]=-1;
      back[x]=-1;
    }
    else{
      cin >> x;
      ll head = x;
      while(front[head]!=-1){
        head = front[head];
      }
      // cout << "head:" << head << endl;
      vector<ll> output_list;
      output_list.push_back(head);
      while(back[head]!=-1){
        head = back[head];
        output_list.push_back(head);
      }
      cout << output_list.size() << " ";
      for(ll i=0;i<output_list.size();i++){
        cout << output_list[i] << " ";
      }
      cout << endl;

    }
  }

  return 0;
}