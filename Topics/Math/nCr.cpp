#include <bits/stdc++.h>
using namespace std;
#define ll long long
// prime mod
const ll MAXX = 2*1e6;
const ll mod = 1e9+7;
ll fact[MAXX], inv[MAXX];

ll Pow(ll a, ll b){ ll ans = 1; while(b){ if(b&1) ans = (ans*a)%mod; a = (a*a)%mod; b >>= 1; } return ans; }

void pre_nCr(){
	fact[0] = inv[0] = 1;
	for(int i = 1; i < MAXX; ++i) fact[i] = (fact[i-1]*i)%mod;
	inv[MAXX-1] = Pow(fact[MAXX-1],mod-2);
	for(int i = MAXX-2; i >= 1; --i) inv[i] = (inv[i+1]*(i+1))%mod;
}

// non-prime mod, low constraints
ll rec(ll n, ll k){
	if(k==0 || k==n) return 1LL;
	if(dp[n][k] != -1) return dp[n][k];
	return dp[n][k] = rec(n-1,k-1) + rec(n-1,k);
}
