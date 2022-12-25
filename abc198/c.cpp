#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {

  ll R, X, Y; cin >> R >> X >> Y;

  ll d2 = X*X + Y*Y;

  ll cnt = 0;

  ll k;
  ll index_i,index_k;
  bool flag_equal=false;
  for(index_i=1;index_i*index_i<=20000000000;index_i++){
    if(index_i*index_i == d2/(R*R) && d2%(R*R)==0){
      flag_equal=true;
      break;
    }
  }
  if(flag_equal){
    cnt = index_i;
  }
  else if(d2<R*R){
    cnt=2;
  }else{
    for(index_k=1;index_k*index_k<=20000000000;index_k++){
      if(index_k*index_k > d2/(R*R)){
        break;
      }
    }
    cnt = index_k;
  }

  cout << cnt << endl;

  return 0;
}