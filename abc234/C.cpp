#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bitset>
typedef long long ll;
using namespace std;

int main(int argc, const char * argv[]) {

  long long K; cin >> K;
  long long k,x,temp1,temp2;
  for (k=0;k<K;k++){
    temp1 = std::pow(2,k);
    temp2 = std::pow(2,k+1)-1;
    if(temp1 <= K && temp2 >= K){
      x = k;
      break;
    }
  }
  vector<long long> A(x+1);
  
  long long left = std::pow(2,x);
  long long right = std::pow(2,x+1)-1;
  long long ave;
  long long i;
  A.at(0) = 2;
  for(i=1;i<x+1;i++){
    ave = (left + right)/2;
    cout << i << " : left= " << left << ", ave=" << ave << ", right =" << right;

    if(ave >= K){
      cout << "    K = " << K << "は中間値以下" << endl;
      A.at(i) = 0;
      right = ave;
    }else{
      cout << "    K = " << K << "は中間値より大きい" << endl;
      A.at(i) = 2;
      left = ave + 1;
    }
  }

  for (i=0;i<x+1;i++){
    cout << A.at(i);
  }
  cout << endl;

   return 0;
}




