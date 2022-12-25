#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long

vector<char> s;

vector<char> toBinary(unsigned ll n)
{
    vector<char> r(60,'0');

    ll cnt=0;
    while (n != 0){
        r[cnt] = ( n % 2 == 0 ? '0' : '1' );
        n /= 2;
        cnt++;
    }
    return r;
}

ll hoge=0;
unsigned ll POW2_59;


unsigned ll toDecimal(vector<char> list){
  unsigned ll ans=0;
  unsigned ll pow2_59 = POW2_59;
  for(ll i=0;i<60;i++){
    if(list[i]=='1'){
      ans+=pow2_59;
    }
    pow2_59=pow2_59/2;
  }
  return ans;
}

//list : 上位：2^0, 下位：2^59;
void dfs(vector<char> list,ll index){
  if(list.size()==60){
    cout << toDecimal(list) << endl;
    return;
  }

  list.push_back('0');
  dfs(list,index-1);
  list.pop_back();

  if(s[index]=='1'){
    list.push_back('1');
    dfs(list,index-1);
    list.pop_back();
  }

}

unsigned ll my2pow(void){
  unsigned ll ans=1;
  for(ll i=0;i<59;i++){
    ans*=2;
  }
  return ans;
}

int main(int argc, const char * argv[]) {

  ll N; cin >> N;
  s = toBinary(N);//11の場合は、1011

  POW2_59=my2pow();

  ll index=59;
  dfs(vector<char>({'0'}),index-1);
  if(s[59]=='1') dfs(vector<char>({'1'}),index-1);

  return 0;
}