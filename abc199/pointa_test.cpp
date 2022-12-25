#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {

  vector<char> A = {'1','2','3','4','5'};
  cout << &(A[0]) << endl;
  cout << &(A[1]) << endl;
  cout << &(A[2]) << endl;
  cout << &(A[3]) << endl;
  cout << &(A[4]) << endl;
  cout << &A << endl;
  cout << A.data() << endl;
  char* p = A.data();
  cout << endl;
  cout << p << endl;





  return 0;
}