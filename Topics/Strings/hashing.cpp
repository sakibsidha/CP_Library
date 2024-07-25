#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod1 = 911382323, mod2 = 972663749, b1 = 137, b2 = 139;
const ll mxN = 1e6+10;
ll pow_b1[mxN], pow_b2[mxN], invpow_b1[mxN], invpow_b2[mxN];

ll power(ll a, ll b, ll mod){
  ll ans = 1;
  while(b){
    if(b&1) ans = (ans * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return ans;
}

void pre(){
  pow_b1[0] = pow_b2[0] = 1;
  for(int i = 1; i < mxN; ++i){
    pow_b1[i] = pow_b1[i-1] * b1 % mod1;
    pow_b2[i] = pow_b2[i-1] * b2 % mod2;
  }
  invpow_b1[mxN-1] = power(pow_b1[mxN-1], mod1-2, mod1);
  invpow_b2[mxN-1] = power(pow_b2[mxN-1], mod2-2, mod2);
	for(int i = mxN-2; i >= 0; --i){
    invpow_b1[i] = (invpow_b1[i+1]*b1)%mod1;
    invpow_b2[i] = (invpow_b2[i+1]*b2)%mod2;
  }
}

vector<pair<ll,ll>> getPrefixHash(string& s){
  ll n = s.size();
  vector<pair<ll,ll>> ret(n);
  for(int i = 0; i < n; ++i){
    if(!i){
      ret[i].first =  (s[i] * pow_b1[i] % mod1) % mod1;
      ret[i].second =  (s[i] * pow_b2[i] % mod2) % mod2;
    }
    else{
      ret[i].first = (ret[i-1].first +  s[i] * pow_b1[i] % mod1) % mod1;
      ret[i].second = (ret[i-1].second +  s[i] * pow_b2[i] % mod2) % mod2;
    }
  }
  return ret;
}

pair<ll,ll> getSubstrHash(ll l, ll r, vector<pair<ll,ll>>& pf_hash){
  if(l == 0) return pf_hash[r];
  else{
    pair<ll,ll> ans;
    ans.first = (pf_hash[r].first - pf_hash[l-1].first + mod1) % mod1;
    ans.first = (ans.first * invpow_b1[l]) % mod1;
    ans.second = (pf_hash[r].second - pf_hash[l-1].second + mod2) % mod2;
    ans.second = (ans.second * invpow_b2[l]) % mod2;
    return ans;
  }
} 

void solve(){
  // hash
  string s; cin >> s;
  auto [a, b] = getHash(s);
  cout << a << " " << b << "\n";
  
  // substring hash
  vector<pair<ll,ll>> pf_hash = getPrefixHash(s);
  int l, r; cin >> l >> r;
  auto [c, d] = getSubstrHash(l-1, r-1, pf_hash);
  cout << c << " " << d << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  pre();
  int tc; cin >> tc;
  while(tc--)
    solve();

  return 0;
}
