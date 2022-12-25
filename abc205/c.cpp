#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {

  ll A,B,C; cin >> A >> B >> C;

  if(C%2==1){
    if(A==B) cout << "=" << endl;
    else if(A>B) cout << ">" << endl;
    else cout << "<" << endl;
  }else{
    if(abs(A)==abs(B)) cout << "=" << endl;
    else if(abs(A)>abs(B)) cout << ">" << endl;
    else cout << "<" << endl;
  }

  return 0;
}