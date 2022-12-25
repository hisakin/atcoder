#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {






}



/* 役割：自然数Nを素因数分解する */
/* 計算量：O(√N)*/
/* 返り値：例 N=20の場合は、({2,2},{5,1})...つまり 2^2*5^1 */
vector<pair<long,long>> prime_factorize(long long N){
  vector<pair<long,long>> ret;
  for(long long i=2;i*i<=N;i++){
    if(N%i!= 0) continue;
    long long ex = 0; /* 指数 */
    /* 割り切れる限り、割り続ける */
    while(N%i==0){
      ex++;
      N /= i;
    }
    /* その結果をpush */
    ret.push_back({i,ex});
  }
    /* 残ったものは1 又は 1より大きい素数。素数の場合は追加 */
  if(N!=1)
    ret.push_back({N,1});
  return ret;
}