#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bitset>
typedef long long ll;
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

const int mod = 1000000007;

struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}


struct combination {
  vector<mint> fact, ifact;
  combination(int n):fact(n+1),ifact(n+1) {
    assert(n < mod);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
  }
  mint operator()(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n]*ifact[k]*ifact[n-k];
  }
};




int main(int argc, const char * argv[]) {
    double A,B,H,M;
    cin >> A >> B >> H >> M;
    double p = 3.141592653589793;
    
    double theta_A = (2.0*p*M)/60.0;
    double theta_B = (2.0*p*H)/12.0;
    
    double theta;
    if(theta_A > theta_B){
        theta = theta_A - theta_B;
    }else{
        theta = theta_B - theta_A;
    }
    
    double x = A*A + B*B -2.0 * A * B * cos(theta);
    x = sqrt(x);
    cout << x << endl;
    
    double A_cos = cos(2.0*p*((H+M/60.0)/12.0);
    double A_sin = sin((2.0*p*H+M/60.0)/12.0);
    double B_cos = cos((2.0*p*M)/60.0);
    double B_sin = sin((2.0*p*M)/60.0);
    
    double X_A = -A*A_sin;
    double Y_A = A*A_cos;
    double X_B = -B*B_sin;
    double Y_B = B*B_cos;
    
    double dist = (X_B - X_A)*(X_B - X_A) + (Y_B - Y_A)*(Y_B - Y_A);
    dist = sqrt(dist);
    
    cout << fixed << setprecision(20) << dist << endl;

    
   return 0;
}

