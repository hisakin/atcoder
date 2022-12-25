#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;

int main(int argc, const char * argv[]) {

 ll N, M; cin >> N >> M;

  vector<ll> a(M);
  vector<ll> b(M);
  Graph graph(N);

  cout << endl;

  for(ll i=0;i<M;i++){
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
    graph[a[i]].push_back(b[i]);
    graph[b[i]].push_back(a[i]);
    cout << "a[" << i <<"]：" << a[i] << endl;
    cout << "a[" << i <<"]のアドレス：" << &a[i] << endl;
    cout << "b[" << i <<"]：" << b[i] << endl;
    cout << "b[" << i <<"]のアドレス：" << &b[i] << endl;
    cout << "graph[" << a[i] <<"]のアドレス：" << &graph[a[i]] << endl;
    cout << "graph[" << b[i] <<"]のアドレス：" << &graph[b[i]] << endl;

  }
    
  // ll a,b;
  // Graph graph(N);
  // for(ll i=0;i<M;i++){
  //   cin >> a >> b;
  //   a--; b--;
  //   graph[a].push_back(b);
  //   graph[b].push_back(a);
  
  // }

  return 0;
}
