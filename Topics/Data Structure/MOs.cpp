//  find for q queries the number of unique elements in range l to r in an array of size n
// complexity: O((n+q)⋅ sqrt(n))

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int block_size;

void solve() {
  int n, q; cin >> n >> q;
  vector<int> v(n), fq(n + 1), ans(q);
  vector<array<int, 3>> queries;
  for (auto &i : v) cin >> i;
  for (int i = 0; i < q; ++i) {
    int l, r; cin >> l >> r, --l, --r;
    queries.push_back({l, r, i});
  }
  block_size = max(1, (int)sqrt(n));
  sort(queries.begin(), queries.end(), [&] (const array<int, 3>& a, const array<int, 3>& b) {
    if (a[0] / block_size != b[0] / block_size) return a < b;
    return (a[0] / block_size & 1) ? (a[1] < b[1]) : (a[1] > b[1]);
  });
  int cur = 0;
  auto add = [&] (int x) {
    ++fq[x];
    if (fq[x] == 1) cur++;
  };
  auto rem = [&] (int x) {
    --fq[x];
    if (fq[x] == 0) cur--;
  };
  int cur_l = 0, cur_r = -1;
  for (auto &[l, r, idx] : queries) {
    while (cur_l > l) add(v[--cur_l]);
    while (cur_r < r) add(v[++cur_r]);
    while (cur_l < l) rem(v[cur_l++]);
    while (cur_r > r) rem(v[cur_r--]);
    ans[idx] = cur;
  }
  for (int i = 0; i < q; ++i) {
    cout << ans[i] << "\n"; 
  }
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // int tc; cin >> tc;
  // while (tc--)
    solve();

  return 0;
}
