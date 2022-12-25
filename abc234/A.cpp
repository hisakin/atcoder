#include <bits/stdc++.h>
using namespace std;

int f(int x){
  return x*x + 2*x +3;
}

int main() {
  int x;
//  cout << "Hello, world!" << endl;
  std::cin >> x;
  int ans;
  ans = f(f(f(x)+x) + f(f(x)));
  cout << ans << endl;
}
