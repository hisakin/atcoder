#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {


  ll N; cin >> N;
  vector<unsigned ll> A(N);
  for(ll i=0;i<N;i++){
    cin >> A[i];
  }

  vector<unsigned ll> CNT(2*100000+1,0);

  for(ll i=0;i<2*100000+1;i++){
    if(i>=N) break;
    CNT[A[i]]++;
  }

  vector<ll> kind;
  ll kind_num = 0;
  for(ll i=0;i<2*100000+1;i++){
     if(CNT[i]>0){
       kind.push_back(CNT[i]);
       kind_num++;
     }
  }

  unsigned ll sum=0;

  for(ll i=0;i<kind_num;i++){

    unsigned ll d = kind[i];
    sum += d*(d-1)/2*(N-d) + d*(d-1)*(d-2)/6;
  }


  unsigned ll ans = N*(N-1)*(N-2)/6 - sum;

  cout << ans << endl;



}