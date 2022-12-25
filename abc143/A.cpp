#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bitset>
typedef long long ll;
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(int argc, const char * argv[]) {
  ll A,B; cin >> A >> B;
  cout << max(0,A-2*B) << endl;

  return 0;
}


