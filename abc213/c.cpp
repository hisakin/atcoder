#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;

struct POS{
  ll h;
  ll w;
  ll value;
};

bool hcomp( const POS& left, const POS& right ) {
  return left.h == right.h ? left.w < right.w : left.h < right.h;
}
bool wcomp( const POS& left, const POS& right ) {
  return left.w == right.w ? left.h < right.h : left.w < right.w;
}
bool valuecomp( const POS& left, const POS& right ) {
  return left.value < right.value;
}

int main(int argc, const char * argv[]) {

  ll H,W,N; cin >> H >> W >> N;
  vector<POS> POSLIST(N);
  for(ll i=0;i<N;i++){
    cin >> POSLIST[i].h >> POSLIST[i].w;
    POSLIST[i].h--; POSLIST[i].w--;
    POSLIST[i].value = i+1;
  }

  sort(POSLIST.begin(),POSLIST.end(),hcomp);
  // /*   表示確認  */
  // cout << "H順のソート確認" << endl;
  // for(ll i=0;i<N;i++){
  //   cout << "(" << POSLIST[i].h+1 << "," << POSLIST[i].w+1 << "," << POSLIST[i].value << ")" << endl;
  // }

  ll current_hindex=0;
  for(ll i=0;i<N-1;i++){
    if(POSLIST[i+1].h == POSLIST[i].h){
      POSLIST[i].h=current_hindex;
    }else{
      POSLIST[i].h=current_hindex;
      current_hindex++;
    }
  }
  POSLIST[N-1].h=current_hindex;


  sort(POSLIST.begin(),POSLIST.end(),wcomp);
  // cout << "W順のソート確認" << endl;
  // /*   表示確認  */
  // for(ll i=0;i<N;i++){
  //   cout << "(" << POSLIST[i].h+1 << "," << POSLIST[i].w+1 << "," << POSLIST[i].value << ")" << endl;
  // }

  ll current_windex=0;
  for(ll i=0;i<N-1;i++){
    if(POSLIST[i+1].w == POSLIST[i].w){
      POSLIST[i].w=current_windex;
    }else{
      POSLIST[i].w=current_windex;
      current_windex++;
    }
  }
  POSLIST[N-1].w=current_windex;

  sort(POSLIST.begin(),POSLIST.end(),valuecomp);
  // cout << "VALUE順のソート確認" << endl;
  // /*   表示確認  */
  // for(ll i=0;i<N;i++){
  //   cout << "(" << POSLIST[i].h+1 << "," << POSLIST[i].w+1 << "," << POSLIST[i].value << ")" << endl;
  // }

  for(ll i=0;i<N;i++){
    cout << POSLIST[i].h+1 << " " << POSLIST[i].w+1 << endl;
  }

  return 0;
}