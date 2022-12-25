#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long

ll calc(ll N){

  ll sum = 0;
  while(N>=10){
    ll temp = N % 10;
    sum += temp;
    N = ( N - temp ) / 10;
  }
  sum += N;
  return sum;

}

int main(int argc, const char * argv[]) {

  ll N,A,B;
  ll ans=0;
  cin >> N >> A >> B;
  for(ll i=1;i<=N;i++){
    ll sum = calc(i);
    if(sum >= A && sum <= B){
      ans += i;
    }
  }

  cout << ans << endl;





  return 0;
}