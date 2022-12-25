#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {


  string S; cin >> S;
  ll N = S.size();
  ll head=0, tail=N-1;
  bool flag=true;
  bool ans=true;
  while(head<=tail){
    if(flag){
      if(S[head]==S[tail] && S[tail]=='a'){
        head++; tail--;
        continue;
      }
      if(S[head]==S[tail] && S[tail]!='a'){
        head++; tail--;
        flag=false;
        continue;
      }
      if(S[head]!=S[tail] && S[tail]!='a'){
        ans=false;
        break;
      }
      if(S[head]!=S[tail] && S[tail]=='a'){
        tail--;
        continue;
      }
    }

    if(!flag){
      if(S[head]==S[tail]){
        head++; tail--;
        continue;
      }
      if(S[head]!=S[tail]){
        ans=false;
        break;
      }
    }
  }

  if(ans) cout << "Yes" << endl;
  else{
    cout << "No" << endl;
  }
  return 0;
}