#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 998244353;
ll n, k;
bool mark[1024];

ll f(ll idx, ll mask){

    ll cur = 0;
    if(idx > n-k+1){
        ll new_mask = mask | (1LL << (n-idx+1));
        if(s[idx] == '?'){
            cur += (f(idx-1, mask) + f(idx-1, new_mask)) % mod;
            cur %= mod;
        } else {
            cur += (s[idx] == 'A') ? f(idx-1, mask) : f(idx-1, new_mask);
            cur %= mod;
        }
    } else {
        ll new_mask = 0;
        if(idx == n-k+1) new_mask = mask | (1LL << (n-idx+1));
        else{
            new_mask = 
        }
    }
}

void set(ll l, ll r, ll mask){
    if(l > r){
        mark[mask] = true;
        return;
    }
    ll tmp = mask;
    tmp |= (1LL << l);
    tmp |= (1LL << r);
    set(l+1, r-1, tmp);
    set(l+1, r-1, mask);
}

void solve(){
  cin >> n >> k;
  set(0, k-1, 0);
  cout << f(n-1, 0) << "\n";
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();

  return 0;
}

