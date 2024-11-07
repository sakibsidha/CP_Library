#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> tr, lazy;

void push(int nd, int s, int e) {
  if (lazy[nd]) {
    tr[nd] += (e - s + 1) * lazy[nd];
    if (s != e) {
      lazy[2*nd] += lazy[nd];
      lazy[2*nd + 1] += lazy[nd];
    }
    lazy[nd] = 0;
  }
}

ll query(int nd, int s, int e, int l, int r) {
  push(nd, s, e);
  if (s > r or e < l) return 0;
  if (s >= l and e <= r) {
    return tr[nd];
  }
  int mid = (s + e) >> 1;
  return (query(2*nd, s, mid, l, r) + query(2*nd+1, mid + 1, e, l, r));
}

void update(int nd, int s, int e, int l, int r, int v) {
  push(nd, s, e);
  if (s > r or e < l) return;
  if (s >= l and e <= r) {
    lazy[nd] += v;
    push(nd, s, e);
    return;
  }
  int mid = (s + e) >> 1;
  update(2*nd, s, mid, l, r, v);
  update(2*nd+1, mid + 1, e, l, r, v);
  tr[nd] = tr[2*nd] + tr[2*nd + 1];
}

void solve() {
  int n; cin >> n;
  int q; cin >> q;
  vector<ll> a(n);
  // for (int i = 0; i < n; ++i) {
  //   cin >> a[i];
  // }
  int sz = n;
  while (__builtin_popcount(sz) != 1) {
    sz++;
    a.push_back(0);
  }
  tr.resize(2*sz);
  lazy.resize(2*sz);
  for (int i = 0; i < n; ++i) {
    tr[sz + i] = a[i];
  }
  for (int i = sz - 1; i >= 1; --i) {
    tr[i] = tr[2*i] + tr[2*i + 1];
  }
  while (q--) {
    int t; cin >> t;
    if (t == 2) {
      int l, r; cin >> l >> r;
      cout << query(1, 0, sz-1, l, r-1) << "\n";
    }
    else {
      int l, r, v; cin >> l >> r >> v;
      update(1, 0, n-1, l, r-1, v);
    }
  }
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // int tc; cin >> tc;
  // while(tc--)
    solve();

  return 0;
}
