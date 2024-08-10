#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// prime mod, O(N) precalc
const ll mxN = 2*1e6; // change
const ll mod = 1e9+7; // change
int fact[mxN], inv[mxN]; // fact and inverse fact array

ll power(ll a, ll b){ ll ans = 1; while(b){ if(b&1) ans = (ans*a)%mod; a = (a*a)%mod; b >>= 1; } return ans; }

void preFact(){
	fact[0] = inv[0] = 1;
	for(int i = 1; i < mxN; ++i) fact[i] = (fact[i-1]*1LL*i)%mod;
	inv[mxN-1] = power(fact[mxN-1],mod-2);
	for(int i = mxN-2; i >= 1; --i) inv[i] = (inv[i+1]*1LL*(i+1))%mod;
}

ll nCr(ll n, ll r){
  if(n < r) return 0LL;
  ll ret = (((fact[n]*1LL*inv[r])%mod)*1LL*inv[n-r])%mod;
  return ret;
}

// non-prime mod, low constraints, O(N^2)
ll rec(ll n, ll k){
	if(k==0 || k==n) return 1LL;
	if(dp[n][k] != -1) return dp[n][k];
	return dp[n][k] = rec(n-1,k-1) + rec(n-1,k);
}
