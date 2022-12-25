#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {

  string S; cin >> S;
  S.push_back('E');
  ll K; cin >> K;
  ll Xnum=0;
  ll Pnum=0;
  ll ans=0;

  if(K==0){
    ll index=0;
    ll temp=0;
    while(S[index]!='E'){
      if(S[index]=='X'){
        temp++;
      }else{
        temp=0;
      }
      index++;
      ans = max(ans,temp);
    }
    cout << ans << endl;
    return 0;
  }


  ll left=0,right=0;//区間[left,right)
  // rightの初期値
  while(S[right]!='E'){
    if(S[right]=='X'){
      Xnum++;
    }else if(S[right]=='.' && Pnum<K){
      Pnum++;
    }else{
      break;
    }
    right++;
  }
  ans = Xnum + Pnum;

  if(S[right]=='E'){
    cout << ans << endl;
    return 0;
  }

  while(S[right]!='E'){
    // cout << "left:" << left << "  right:" << right << " Xnum:" << Xnum << "  Pnum:" << Pnum << " ans:" << ans << endl;
    //leftは1つずつ進める。
    ll flag=false;
    if(S[left]=='.'){
      flag=true;
    }else{
      Xnum--;
    }
    left++;

    //rightはleftがPnumを減らした時だけ進められる。
    if(flag){
      right++;
      while(S[right]=='X'){
        Xnum++;
        right++;
      }
      // if(S[right]=='.') Pnum++;
    }
    
    ans = max(ans,Xnum + Pnum);
  }

  cout << ans << endl;
  return 0;
}