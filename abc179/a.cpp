#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {

  string str; cin >> str;

  ll len;
  len = str.length();
  if(str[len-1] == 's'){
    str += "es";
  }else{
    str += "s";
  }
  cout << str << endl;
  
}