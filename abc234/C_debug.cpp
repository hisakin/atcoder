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
  // cout << " K = " << K << endl;
  long long k,x,temp1,temp2;
  for (k=0;k<K;k++){
    temp1 = std::pow(2,k);
    temp2 = std::pow(2,k+1);
    if(temp1 <= K && temp2 > K){
      x = k;
      break;
    }
  }
  // cout << "x : " <<x << endl;
  vector<long long> A(x+1);
    
  long long left = std::pow(2,x);
  long long right = std::pow(2,x+1)-1;
  long long target=K;
  long long i;

  for(i=x;i>=0;i--){
    if(lldiv(target,(long long)std::pow(2,i)).quot == 1){
      target = lldiv(target,(long long)std::pow(2,i)).rem;
      A.at(i) = 2;
    }else{
      A.at(i) = 0;
    }
  }


  for (i=x;i>=0;i--){
    cout << A.at(i);
  }
  cout << endl;
  return 0;
}




