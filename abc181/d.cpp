#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {


  string S; cin >> S;
  vector<ll> multi8_2;
  vector<ll> multi8_3;
  if(S.size()==1){
    if(S[0]=='8'){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
    return 0;
  }

  for(ll i=16;i<1000;i+=8){
    if(i>=100){
      ll itemp=i;
      if(itemp%10==0) continue;
      itemp/=10;
      if(itemp%10==0) continue;
      multi8_3.push_back(i);
    }else{
      ll itemp=i;
      if(itemp%10==0) continue;
      multi8_2.push_back(i);
    }
  }

  map<ll,ll> MAP;
  for(ll i=0;i<S.size();i++){
    MAP[S[i]-'0']++;
  }


  if(S.size()==2){
    bool ans=false;
    for(ll i=0;i<multi8_2.size();i++){
      ll t1 = multi8_2[i]%10;
      ll t2 = (multi8_2[i]/10)%10;
      if(t1==t2 && MAP[t1]>=2){
        ans=true;
        break;
      }
      else if(t1!=t2 && MAP[t1]>=1 && MAP[t2]>=1){
        ans=true;
        break;
      }
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
  }


  bool ans=false;
  for(ll i=0;i<multi8_3.size();i++){
    ll t1 = multi8_3[i]%10;
    ll t2 = (multi8_3[i]/10)%10;
    ll t3 = (multi8_3[i]/100)%10;
    // cout << "t3:" << t3 << " t2:" << t2 << " t1:" << t1 << endl;
    if(t1==t2 && t2==t3 && MAP[t1]>=3){
      ans=true;
      break;
    }
    if(t1==t2 && t1!=t3 && MAP[t1]>=2 && MAP[t3]>=1){
      ans=true;
      break;
    }
    if(t1==t3 && t1!=t2 && MAP[t1]>=2 && MAP[t2]>=1){
      ans=true;
      break;
    }
    if(t2==t3 && t1!=t2 && MAP[t2]>=2 && MAP[t1]>=1){
      ans=true;
      break;
    }
    if( t1!=t2 && t2!=t3 && t3!=t1 && MAP[t1]>=1 && MAP[t2]>=1 && MAP[t3]>=1){
      ans=true;
      break;
    }
  }
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}