#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bitset>
typedef long long ll;
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef pair<int,int> P;

const int MOD = 1000000007;

ll N;

ll calc_head(ll x){
  ll d=100000;
  ll ret=1;
  while(d!=0){
    if(x/d!=0){
      ret = x/d;
      break;
    }
    d/=10;
  }
  return ret;
}

ll calc_tail(ll x){
  return x%10;
}

ll calc_digit(ll x){
  ll d=100000;
  ll cnt=0;
  while(x!=0){
    x /= 10;
    cnt++;
  }

  return cnt;
}


int main(int argc, const char * argv[]) {
  cin >> N;

  ll cnt=0;
  ll cnt1=0;
  ll cnt2=0;
  ll cnt3=0;
  for(ll i=1;i<=N;i++){
    ll head = calc_head(i);
    ll tail = calc_tail(i);
    ll N_digit = calc_digit(N);
    if(tail==0) continue;

    // 1桁の相手の個数をカウント
    if(head==tail) cnt1++;

    // Nの桁数-1までの相手の個数をカウント
    ll d=1;
    for(ll i=1;i<N_digit-1;i++){
      cnt2 += d;
      d *= 10;
    }


    // Nの桁数の場合の相手の個数をカウント
    ll x = tail*pow(10,N_digit-1)+head;
    if(N>=x && N_digit!=1){
      ll N_head = calc_head(N);
      ll N_tail = calc_tail(N);
      ll x_head = tail;
      ll x_tail = head;
      if(N_head==x_head){
        ll save_N=N;
        if(N_tail>x_tail){
          save_N = (save_N/10)*10 + x_tail;
        }else if(N_tail<x_tail){
          save_N = (save_N/10)*10  + x_tail - 10;
        }

        cnt3 += (save_N - x)/10 + 1;
        
      }else if(N_head > x_head){
        cnt3 += d;
      }
    }
    // printf("i:%ld cnt1:%ld cnt2:%ld cnt3:%ld total:%ld \n", i,cnt1,cnt2,cnt3,cnt1+cnt2+cnt3);

    cnt+=cnt1+cnt2+cnt3;
    cnt1=0; cnt2=0; cnt3=0;

  }

  cout << cnt << endl;
  return 0;
}
