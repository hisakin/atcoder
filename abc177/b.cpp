#include <bits/stdc++.h>
using namespace std;
int main(int argc, const char * argv[]) {

  string S,T; cin >> S >> T;

  int i,j,k;
  int min=T.size();
  int min_temp=T.size();

  for(i=0;i<S.size();i++){
    min_temp = T.size();
    // cout << "i=" << i<<endl;
    if(i+T.size()-1>=S.size())
      break;
    for(j=0;j<T.size() && i+j<S.size();j++){
      // cout << "S.at(" << j+i << ") =" << S.at(j+i) << "   " << "T.at(" << j << ") =" << T.at(j) << endl;
      if(S.at(i+j)==T.at(j)){
        min_temp--;
      }
    }
    if(min_temp<min)
      min = min_temp;
  }

  cout << min << endl;

}