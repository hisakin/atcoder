#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {

  map<string,int> m;
  m["Tuesday"]=4;
  m["Wednesday"]=3;
  m["Thursday"]=2;
  m["Friday"]=1;
  m["Monday"]=5;
  
  string S; cin >> S;
  cout << m[S] << endl;

  return 0;
}