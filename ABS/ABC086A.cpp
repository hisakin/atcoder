#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {


  ll a,b; cin >> a >> b;
  ll cal = a*b;

  if(cal%2==0){
    cout << "Even" << endl;
  }else{
    cout << "Odd" << endl;
  }




  return 0;
}