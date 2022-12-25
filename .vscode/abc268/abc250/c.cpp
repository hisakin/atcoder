#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;
int main(int argc, const char * argv[]) {

 ll N,Q; cin >> N >> Q;
 vector<ll> X(Q); 
 for(ll i=0;i<Q;i++){
  cin >> X[i];
  X[i]--;
 }

 vector<ll> List(N);
 vector<ll> Index(N);

for(ll i=0;i<N;i++){
  List[i]=i;
  Index[i]=i;
}
 for(ll i=0;i<Q;i++){

  if(Index[X[i]]==N-1){
    ll Index_left = Index[X[i]];
    ll Index_right = Index[X[i]]-1;
    ll Xi = X[i];
    ll IndexXi = Index[Xi];
    Index[Xi]--;
    Index[List[IndexXi-1]]++;
    swap(List[Index_left],List[Index_right]);
  }
  else{
    ll Index_left = Index[X[i]];
    ll Index_right = Index[X[i]]+1;
    ll Xi = X[i];
    ll IndexXi = Index[Xi];
    Index[Xi]++;
    Index[List[IndexXi+1]]--;
    swap(List[Index_left],List[Index_right]);
  }



 }
 
  for(ll i=0;i<N;i++){
    cout << List[i]+1 << " " ;
  }
  cout << endl;


  return 0;
}