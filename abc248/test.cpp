#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long
using Graph = vector<vector<ll>>;

vector<ll> a = {2,5,7,9,13};

// index が条件を満たすかどうか
bool isOK(int index, int key) {
    if (a[index] >= key) return true;
    else return false;
}

// 汎用的な二分探索のテンプレ
int binary_search(int key) {
    int ng = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
    int ok = (int)a.size(); // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;

        if (isOK(mid, key)) ok = mid;
        else ng = mid;
    }
    return ok;
}


int main(int argc, const char * argv[]) {

  cout << binary_search(6) << endl;
  cout << binary_search(5) << endl;
  cout << binary_search(7) << endl;
  cout << binary_search(20) << endl;
  cout << binary_search(0) << endl;
  cout << binary_search(-1) << endl;

  return 0;
}