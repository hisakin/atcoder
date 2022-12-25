#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {


  ll N;cin >> N;
  ll D1[N], D2[N];
  ll i;
  for(i=0;i<N;i++){
    cin >> D1[i] >> D2[i];
  }

  ll cnt=0;
  bool ans = false;
  for(i=0;i<N;i++){
    if(D1[i]==D2[i]){
      cnt++;
    }else{
      cnt=0;
    }
    if(cnt==3)
      ans = true;
  }

  if(ans){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }

}