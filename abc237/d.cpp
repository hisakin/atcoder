#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {

  ll N; cin >> N;
  string S; cin >> S;
  list<ll> LIST;
  LIST.push_front(0);
  auto itr = LIST.begin();
  ll itrcnt=0;
  for(ll i=0;i<N;i++){
    

    if(S[i]=='L'){
      // cout << "Lです" << endl;
      LIST.insert(next(itr,itrcnt),i+1);
      itrcnt--;
    }else{
      // cout << "Rです" << endl;
      itrcnt++;
      LIST.insert(next(itr,itrcnt),i+1);
      itrcnt--;
    }

    // cout << "現在のitr:" << *itr << endl;
    // for(auto itrq=LIST.begin(); itrq!=LIST.end();itrq++){
    //   cout << *itrq << " ";
    // }
    // cout << endl;

  }

  for(auto itrq=LIST.begin(); itrq!=LIST.end();itrq++){
    cout << *itrq << " ";
  }
  cout << endl;

  
  return 0;
}