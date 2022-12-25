#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {


  ll X,Y,Z; cin >> X >> Y >> Z;

  bool IsNatural;
  if(X>=0) IsNatural=true;
  else IsNatural=false;

  ll dist = 0;
  if(IsNatural)
  {
    if(Y<X && Y<Z && Y>0){
      cout << -1 << endl;
      return 0;
    }
    if(Y<X && Y>0){
      dist = abs(Z) + abs(X-Z);
    }
    else{
      dist = abs(X);
    }

  }else
  {
    if(Y>X && Y>Z && Y<0){
      cout << -1 << endl;
      return 0;
    }
    if(Y>X && Y<0){
      dist = abs(Z) + abs(X-Z);
    }
    else{
      dist = abs(X);
    }
  }

  cout << dist << endl;
  return 0;
}



