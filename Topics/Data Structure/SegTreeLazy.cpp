#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 1e5+10;
int a[mxN];
int tr[4*mxN], lazy[4*mxN];

void pull(int node){
  tr[node] = tr[2*node] + tr[2*node+1];
}

void push(int node, int b, int e){
  if(lazy[node] == 0) return;
  tr[node] = tr[node] + lazy[node] * (e - b + 1);
  if(b != e){
    lazy[2*node] = lazy[2*node] + lazy[node];
    lazy[2*node+1] = lazy[2*node+1] + lazy[node];
  }
  lazy[node] = 0;
}

void build(int node, int b, int e){
  lazy[node] = 0;
  if(b == e){
    tr[node] = a[b];
    return;
  }
  int mid = (b + e) >> 1;
  build(2*node, b, mid);
  build(2*node+1, mid+1, e);
  pull(node);
}

int combine(int left, int right){
  return left + right;
}

void update(int node, int b, int e, int l, int r, int v){
  push(node, b, e);
  if(b > r or e < l) return;
  if(b >= l and e <= r){
    lazy[node] = v;
    push(node, b, e);
    return;
  }
  int mid = (b + e) >> 1;
  update(2*node, b, mid, l, r, v);
  update(2*node+1, mid+1, e, l, r, v);
  pull(node);
}

int query(int node, int b, int e, int l, int r){
  push(node, b, e);
  if(b > r or e < l) return 0;
  if(b >= l and e <= r) return tr[node];
  int mid = (b + e) >> 1;
  int left = query(2*node, b, mid, l, r);
  int right = query(2*node+1, mid+1, e, l, r);
  return combine(left, right);
}

void solve(){
  int n; cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> a[i];
  }
  build(1, 0, n-1);
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  // int tc; cin >> tc;
  // while(tc--)
    solve();

  return 0;
}
