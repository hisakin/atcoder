#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long

string S;

ll check_word(ll head){
    // cout << "head = " << head << ": S.size = " << S.size() << endl;
    if(S.size()==head) return 0;

    //[dreameraser]
    if(S.size()-1 >= head+10){
      string str = S.substr(head,11);
      if(str.compare("dreameraser")==0){
        // cout << "[dreameraser]" << endl;
        return 11;
      }
    }

    //[dreamerase]
    if(S.size()-1 >= head+9){
      string str = S.substr(head,10);
      if(str.compare("dreamerase")==0){
        // cout << "[dreamerase]" << endl;
        return 10;
      }
    }    

    //[dreamer]
    if(S.size()-1 >= head+6){
      string str = S.substr(head,7);
      if(str.compare("dreamer")==0){
        // cout << "[dreamer]" << endl;
        return 7;
      }
    }    

    //[eraser]
    if(S.size()-1 >= head+5){
      string str = S.substr(head,6);
      if(str.compare("eraser")==0){
        // cout << "[eraser]" << endl;
        return 6;
      }
    }    
    //[dream]
    if(S.size()-1 >= head+4){
      string str = S.substr(head,5);
      if(str.compare("dream")==0){
        // cout << "[dream]" << endl;
        return 5;
      }
    }    
    //[erase]
    if(S.size()-1 >= head+4){
      string str = S.substr(head,5);
      if(str.compare("erase")==0){
        // cout << "[erase]" << endl;
        return 5;
      }
    }

    // cout << "[それ以外]" << endl;
    return -1;

}

int main(int argc, const char * argv[]) {

  cin >> S;
  bool ans;
  for(ll i=0;;){
    ll ret = check_word(i);
    // cout << "ret = " << ret << endl;
    if(ret == -1){
      ans = false;
      break;
    }
    if(ret == 0){
      ans = true;
      break;
    }
    i+=ret;
  }


  if(ans){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }




  return 0;
}