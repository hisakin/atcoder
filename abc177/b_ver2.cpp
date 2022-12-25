#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {

  string S,T; cin >> S >> T;
  int i,j;
  int min=T.size();
  int min_temp=T.size();
  int match_number = 0;
  int match_number_max = 0;

  for(i=0;i+T.size()-1<S.size();i++){
    match_number = 0;
    for(j=0;j<T.size();j++){
      if(S.at(i+j)==T.at(j)){
        match_number++;
      }
    }
    if(match_number > match_number_max)
      match_number_max = match_number;
  }

  cout << T.size() - match_number_max << endl;

}