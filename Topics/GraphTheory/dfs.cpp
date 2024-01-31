#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, e;
vector<ll> g[100];
bool vis[101];

void dfs(ll n){
	vis[n] = true;
	cout << n << endl;
	for(auto u: g[n]){
		if(!vis[u]) dfs(u);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> e;
	for(ll i = 1; i <=e;++i){
		ll x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1);
	
	return 0;
}
