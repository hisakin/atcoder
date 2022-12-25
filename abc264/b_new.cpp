#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {

    ll R,C; cin >> R >> C;
    R=abs(R-8);
    C=abs(C-8);
    if(max(R,C)%2==0){
      cout << "white" << endl;
    }else{
      cout << "black" << endl;
    }






  return 0;
}