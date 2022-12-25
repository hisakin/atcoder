#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {

  ll N; cin >> N;
  vector<ll> A(N);
  for(ll i=0;i<N;i++){
    cin >> A[i];
  }

  if(N==2){
    if((A[0]+A[1])%2 == 1 ){
      cout << -1 << endl;
      return 0;
    }
  }

  vector<ll> even;//偶数
  vector<ll> odd;//奇数
  for(ll i=0;i<N;i++){
    if(A[i]%2==0){
      even.push_back(A[i]);
    }
    else{
      odd.push_back(A[i]);
    }
  }
  
  sort(even.begin(),even.end());
  sort(odd.begin(),odd.end());

  vector<ll> evenmax(2,-1);
  vector<ll> oddmax(2,-1);

  if(even.size()==0){

  }
  else if(even.size()==1){
    evenmax[0]=even[0];
  }
  else{
    evenmax[0]=even[even.size()-1];
    evenmax[1]=even[even.size()-2];
  }

  if(odd.size()==0){

  }
  else if(odd.size()==1){
    oddmax[0]=odd[0];
  }
  else{
    oddmax[0]=odd[odd.size()-1];
    oddmax[1]=odd[odd.size()-2];
  }

  ll ans=0;
  if(evenmax[0]!=-1 && evenmax[1]!=-1){
    ans = max(ans,evenmax[0]+evenmax[1]);
  }

  if(oddmax[0]!=-1 && oddmax[1]!=-1){
    ans = max(ans,oddmax[0]+oddmax[1]);
  }
  cout << ans << endl;
  return 0;
}