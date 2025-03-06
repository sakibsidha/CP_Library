#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define PI acos(-1)

ld a, b, c;

ld f(ld t) {
  return a * t + b * sin (c * PI * t);
}

void solve() {
  cin >> a >> b >> c;
  ld l = 0.0, r = 1e9, ans = -1;
  for (int i = 1; i <= 1000; ++i) {
    ld mid = (l + r) / 2;
    if (f(mid) >= 100.0) {
      ans = mid;
      r = mid;
    } else l = mid;
  }
  cout << fixed << setprecision(15) << ans << "\n";
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int tc = 1;
  // cin >> tc;
  while (tc--) {
    solve();
  }

  return 0;
}
