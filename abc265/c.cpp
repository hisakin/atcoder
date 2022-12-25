#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
int main(int argc, const char * argv[]) {

  ll H,W; cin >> H >> W;
  vector<vector<char>> G(H,vector<char>(W));
  vector<vector<bool>> visited(H,vector<bool>(W,true));
  for(ll i=0;i<H;i++){
    for(ll j=0;j<W;j++){
      cin >> G[i][j];
    }
  }

  visited[0][0]=false;
  ll current_x=0, current_y=0;
  bool cycle_flag=false;
  while(true){

    if(G[current_x][current_y]=='U' && current_x!=0 ){
      if(!visited[current_x-1][current_y]){
        cycle_flag=true;
        break;
      }
      current_x--;
      visited[current_x][current_y]=false;
      continue;
    }
    if(G[current_x][current_y]=='D' && current_x!=H-1){
      if(!visited[current_x+1][current_y]){
        cycle_flag=true;
        break;
      }
      current_x++;
      visited[current_x][current_y]=false;
      continue;
    }
    if(G[current_x][current_y]=='R' && current_y!=W-1 ){
      if(!visited[current_x][current_y+1]){
        cycle_flag=true;
        break;
      }
      current_y++;
      visited[current_x][current_y]=false;
      continue;
    }
    if(G[current_x][current_y]=='L' && current_y!=0){
      if(!visited[current_x][current_y-1]){
        cycle_flag=true;
        break;
      }
      current_y--;
      visited[current_x][current_y]=false;
      continue;
    }

    break;

  }
  if(cycle_flag){
    cout << -1 << endl;
  }else{
    cout << current_x+1 << " " << current_y+1 << endl;
  }
  return 0;
}