#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;


vector<vector<ll>> G;
vector<ll> candidate_x;
vector<ll> candidate_y;

ll N,M;
void BFS(ll sx,ll sy){
  queue<ll> que_x;
  queue<ll> que_y;
  que_x.push(sx);
  que_y.push(sy);

  while(!que_x.empty()){
    ll vx = que_x.front();
    ll vy = que_y.front();
    que_x.pop();
    que_y.pop();

      for(ll i=0;i<candidate_x.size();i++){
        if((vx + candidate_x[i]>=N ) || (vy + candidate_y[i]>=N ) || (vx + candidate_x[i]<0 )|| (vy + candidate_y[i]<0 )){
          continue;
        }
        if(G[vy+candidate_y[i]][vx+candidate_x[i]] != -1) continue;
        G[vy+candidate_y[i]][vx+candidate_x[i]] = G[vy][vx] + 1;
        que_x.push(vx+candidate_x[i]);
        que_y.push(vy+candidate_y[i]);
      }
  }
}


int main(int argc, const char * argv[]) {

  cin >> N >> M;
  vector<vector<ll>> dist20(N,vector<ll>(N,0));
  for(ll y=0;y<N;y++){
    for(ll x=0;x<N;x++){
      ll dist = x*x + y*y;
      dist20[y][x]=dist;
    }
  }

  for(ll y=0;y<N;y++){
    for(ll x=0;x<N;x++){
      if(dist20[y][x]==M){
        candidate_x.push_back(x);
        candidate_y.push_back(y);

        candidate_x.push_back(x);
        candidate_y.push_back(-y);

        candidate_x.push_back(-x);
        candidate_y.push_back(y);

        candidate_x.push_back(-x);
        candidate_y.push_back(-y);
      }
    }
  }


  G=vector<vector<ll>>(N,vector<ll>(N,-1));
  G[0][0]=0;
  BFS(0,0);

  for(ll i=0;i<N;i++){
    for(ll j=0;j<N;j++){
      cout << G[i][j] << " ";
    }
    cout << endl;
  }




  return 0;
}