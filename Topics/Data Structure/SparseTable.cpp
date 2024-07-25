#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define db(x) cerr << #x << ": " << x << "\n";

const int inf = 1e9+10;

void solve(){
  int n; cin >> n;
  vector<int> v(n);
  for(int i = 0; i < n; ++i) cin >> v[i];
  int sz = n;
  while(__builtin_popcount(sz) != 1){
    sz++;
    v.push_back(inf);
  }
  vector<vector<int>> MIN(sz, vector<int>(__builtin_ctz(sz)+1, inf));
  // iterative
  // function<int(int,int)> rmin = [&](int l, int k){
  //   if(k == 0) return v[l];
  //   if(MIN[l][k] != inf) return MIN[l][k];
  //   int mid = l + (1 << (k-1));
  //   return MIN[l][k] = min(rmin(l, k-1), rmin(mid, k-1));
  // };
  for(int i = 0; i < sz; ++i) MIN[i][0] = v[i];
  for(int k = 1; k <= __builtin_ctz(sz); ++k){
    for(int i = 0; i + (1 << k) <= sz; ++i){
      int mid = i + (1 << (k-1));
      MIN[i][k] = min(MIN[i][k-1], MIN[mid][k-1]);
    }
  }
  int q; cin >> q;
  while(q--){
    int l, r; cin >> l >> r, --l, --r;
    int range = r - l + 1;
    int k = 1;
    while((1 << k) <= range) ++k;
    --k;
    // recursive
    // int a = rmin(l, k), b = rmin(r-(1 << k)+1, k);
    int a = MIN[l][k], b = MIN[r-(1<<k)+1][k];
    cout << min(a, b) << "\n";
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  // int tc; cin >> tc;
  // while(tc--)
    solve();

  return 0;
}
