#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long

ll arraysize;
string s_target;
string toBinary(unsigned ll n)
{
    string r;
    while (n != 0){
        r += ( n % 2 == 0 ? "0" : "1" );
        n /= 2;
    }
    return r;
}

unsigned ll  strbin2i (vector<char> s) {

    int out = 0;
    for (int i = 0, size = s.size() ; i < size ; ++i ) {
        out *= 2;
        out += ((int)s[i] == 49) ? 1 : 0;
    }
    return out;
}

void dfs(vector<char> array, ll current_index){
  if(current_index==arraysize){
    cout << strbin2i(array) << endl;
    return;
  }

  if(s_target[current_index]=='1'){
    array.push_back('0');
    dfs(array,current_index+1);
    array.pop_back();
    
    array.push_back('1');
    dfs(array,current_index+1);
    array.pop_back();

  }else{
    array.push_back('0');
    dfs(array,current_index+1);
    array.pop_back();
  }

}

int main(int argc, const char * argv[]) {

  unsigned ll N; cin >> N;
  string s_target = toBinary(N);
  arraysize=s_target.size();
  cout << s_target << endl;

  vector<char> array;
  dfs(array,0);

  return 0;
}