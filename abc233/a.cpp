#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bitset>
typedef long long ll;
using namespace std;

int main(int argc, const char * argv[]) {
  int X,Y; cin >> X >> Y;
  int sub  = Y - X;
  if (sub <= 0){
    cout << 0 << endl;
    return 0;
  }

  int ans = (sub / 10);
  if (sub%10 != 0){
    ans++;
  }


  cout << ans << endl;

   return 0;
}




