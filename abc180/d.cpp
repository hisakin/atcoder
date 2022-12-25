#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll unsigned long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {

  ll X,Y,A,B; cin >> X >> Y >> A >> B;

  ll cnt=0;
  double left = (double)X*A;
  double right = (double)X;
  ll Aonly_cnt;
  ll Y2 = Y;
  while(true){
    if(left >= Y || left >= right + B){
      Aonly_cnt=cnt;
      break;
    }
    Y2 = Y - left;
    cnt++;
    left*=A;
    right*=A;
  }

  ll Bonly_cnt;
  if(Aonly_cnt==0){
      Bonly_cnt = (Y2-X-1)/B;
    }
  else{
      Bonly_cnt = (Y2-1)/B;
    }
  cout << Aonly_cnt + Bonly_cnt << endl;

  return 0;
}