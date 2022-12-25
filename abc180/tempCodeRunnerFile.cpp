#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll unsigned long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {

  ll X,Y,A,B; cin >> X >> Y >> A >> B;

  ll cnt=0;
  ll left = X*A;
  ll right = X;
  ll Aonly_cnt;
  ll Y2 = Y;
  while(true){
    if(left >= Y && right + B >= Y){
      cout << cnt << endl;
      return 0;
    }
    if(left >= right + B){
      Aonly_cnt=cnt;
      break;
    }
    Y2-=left;
    cnt++;
    left*=A;
    right*=A;
  }

  ll Bonly_cnt;
  if((Y2-X)%B == 0){
    Bonly_cnt = (Y2-X)/B - 1;
  }else{
    Bonly_cnt = (Y2-X)/B;
  }

  cout << Aonly_cnt + Bonly_cnt << endl;

  return 0;
}