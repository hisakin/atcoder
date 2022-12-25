#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bitset>

//#include <boost/multiprecision/cpp_dec_float.hpp>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;
//// 任意長整数型
//using Bint = mp::cpp_int;
//// 仮数部が1024ビットの浮動小数点数型(TLEしたら小さくする)
//using Real = mp::number<mp::cpp_dec_float<1024>>;
//
typedef long long ll;
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef pair<int,int> P;

const int MOD = 1000000007;

int main(int argc, const char * argv[]) {
    ll N; cin >> N;
    if(N%2==1){
        cout << 0 << endl;
        return 0;
    }
    ll sum = 0;
    ll five = 5;
    while(2*five<=N){
        sum += N/(2*five);
        five *= 5;
    }
    cout << sum << endl;
}

