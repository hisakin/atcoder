#include <bits/stdc++.h>
using namespace std;

int f(int x){
  return x*x + 2*x +3;
}

int main() {
  int N; cin >> N;
  vector<long> X(N);
  vector<long> Y(N);
  for (int i=0;i<N;i++){
    std::cin >> X.at(i) >> Y.at(i); 
  }

  double max=0;
  double temp;
  for (int i=0;i<N;i++){
    for (int j=0;j<N;j++){
      temp = (double)pow(X.at(j) - X.at(i),2.0) + (double)pow(Y.at(j) - Y.at(i),2.0);
      if (max < temp){
        max = temp;
      }
    }
  }
  cout <<std::fixed << std::setprecision(15) << sqrt(max) << endl;
  
}
