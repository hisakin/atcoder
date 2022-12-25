#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bitset>
typedef long long ll;
using namespace std;

int main(int argc, const char * argv[]) {
  int L,R; cin >> L >> R;
  string S; cin >> S;

  int size = S.size();
  int i;

  int left = L-1;
  int right = R-1;
  for(i=0;i<size;i++){
    if(left>=right){
      break;
    }

    int temp = S.at(left);
    S.at(left) = S.at(right);
    S.at(right) = temp;

    left++;
    right--;

  }

  cout << S << endl;

   return 0;
}




