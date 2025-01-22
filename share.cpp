#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(int u, vector<vector<int>>& adj, vector<bool>& vis) {
  vis[u] = true;
  for (auto v : adj[u]) {
    if (!vis[v]) dfs(v, adj, vis);
  }
}

vector<vector<int>> f(vector<pair<int,int>>& p, int x) {
  int n = p.size() + 1;
  vector<vector<int>> adj(n);
  for (int i = 0; i < n-1; ++i) {
    int u = p[i].first, v = p[i].second;
    if (u != x and v != x){
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
  }
  return adj;
}

vector<vector<int>> f2(vector<pair<int,int>>& p, int x, int y) {
  int n = p.size() + 1;
  vector<vector<int>> adj(n);
  for (int i = 0; i < n-1; ++i) {
    int u = p[i].first, v = p[i].second;
    if (u != x and v != x and u != y and v != y){
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
  }
  return adj;
}

void solve() {
  int n; cin >> n;
  vector<vector<int>> adj(n);
  vector<pair<int, int>> p;
  vector<int> fq(n);
  map<pair<int,int>, int> mp;
  for (int i = 0; i < n-1; ++i) {
    int u, v; cin >> u >> v, --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    p.push_back({u, v});
    fq[u]++;
    fq[v]++;
    mp[{u, v}] = true;
    mp[{v, u}] = true;
  }
  int two = 0, one = 0;
  for (int i = 0; i < n; ++i) {
    if (fq[i] == 2) two++;
    if (fq[i] == 1) one++;
  }
  if (one == 2 and two == n - 2) {
    if (n == 2) cout << 0 << "\n";
    else if (n == 3) cout << 1 << "\n";
    else if (n == 4) cout << 2 << "\n";
    else cout << 3 << "\n";
    return;
  }
  int mx = adj[0].size(), at = 0;
  for (int i = 0; i < n; ++i) {
    if (adj[i].size() > mx) {
      mx = adj[i].size();
      at = i;
    }
  }
  int leaf[n]{};
  for (int i = 0; i < n; ++i) {
    if (adj[i].size() == 1) leaf[adj[i][0]]++; 
  }
  vector<pair<int,int>> can;
  for (int i = 0; i < n; ++i) {
    if (adj[i].size() == mx) {
      can.push_back({leaf[i], i});
    }
  }
  if (can.size() > 2 or (can.size() == 2 and mp[{can[0].second, can[1].second}] == false)) {
    cout << (mx - 1) * 2 + 1 << "\n";
    return;
  }
  sort(can.rbegin(), can.rend());
  at = can[0].second;
  vector<vector<int>> adj2 = f(p, at);
  int mx2 = 0, at2 = -1;
  for (int i = 0; i < n; ++i) {
    if (i == at) continue;
    mx2 = adj2[i].size();
    at2 = i;
    break;
  }
  for (int i = 0; i < n; ++i) {
    if (i == at) continue;
    if (adj2[i].size() > mx2) {
      mx2 = adj2[i].size();
      at2 = i;
    }
  }
  int leaf2[n]{};
  for (int i = 0; i < n; ++i) {
    if (i == at) continue;
    if (adj2[i].size() == 1) leaf2[adj2[i][0]]++; 
  }
  vector<pair<int,int>> can2;
  for (int i = 0; i < n; ++i) {
    if (i == at) continue;
    if (adj2[i].size() == mx2) {
      can2.push_back({leaf2[i], i});
    }
  }
  sort(can2.rbegin(), can2.rend());
  at2 = can2[0].second;
  vector<vector<int>> adj3 = f2(p, at, at2);
  int cnt = 0;
  vector<bool> vis(n);
  for (int i = 0; i < n; ++i) {
    if (i == at or i == at2) continue;
    else {
      if (!vis[i]) {
        dfs(i, adj3, vis);
        cnt++;
      }
    }
  }
  cout << cnt << "\n";
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int tc; cin >> tc;
  while (tc--)
    solve();

  return 0;
}
