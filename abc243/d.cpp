#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;

deque<ll> change10to2(ll num10){
  deque<ll> dq;
  while(num10>0){
    ll amari = num10 % 2;
    if(amari==1) dq.push_front(1);
    else dq.push_front(0);
    num10 = num10 / 2;
  }
  return dq;
}

unsigned ll change2to10(deque<ll> dq){
  unsigned ll index = 1;
  unsigned ll ans = 0;
  ll size = dq.size();
  for(unsigned ll i=0;i<size;i++){
    if(dq.back()==0){
      index *= 2;
    }
    else{
      ans = ans + index * 1;
      index *= 2;
    }
    dq.pop_back();
  }
  return ans;
}

int main(int argc, const char * argv[]) {

  ll N,X; cin >> N >> X;
  string S; cin >> S;

  deque<ll> X_2 = change10to2(X);
  for(ll i=0;i<N;i++){
    char ope = S[i];
    if(ope == 'U'){
      X_2.pop_back();
    }else if(ope == 'L'){
      X_2.push_back(0);
    }else{
      X_2.push_back(1);
    }
  }

  cout << change2to10(X_2) << endl;



  return 0;
}