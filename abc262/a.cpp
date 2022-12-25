#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {

  ll Y; cin >> Y;

  ll x = Y % 4;
  ll add=0;
  if(x==0) add=2;
  else if(x==1) add=1;
  else if(x==2) add=0;
  else add=3;
  cout << Y+add << endl;

  return 0;
}