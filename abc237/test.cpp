#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {

  list<ll> lst;
  lst.push_back(0);

  auto itr = lst.begin();
  cout << *next(itr,0) << endl;

  lst.insert(next(itr,1),1);
  // itr++;
  cout << *next(itr,-1) << endl;
  cout << *next(itr,0) << endl;
  cout << *next(itr,1) << endl;

  return 0;
}