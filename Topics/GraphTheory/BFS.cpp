#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

void solve(){
	int n, e; cin >> n >> e;
	vector<int> g[n+1];
	for(int i = 0; i < e; ++i){
		int x, y; cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	queue<int> q;
	vector<int> level(n+1,inf);
	int source = 1;
	q.push(source);
	level[source] = 0;
	while(!q.empty()){
		int v = q.front();
		q.pop();
		cout << v << " ";
		for(auto u: g[v]){
			if(level[u]==inf){
				level[u] = level[v] + 1;
				q.push(u);
			}
		}
	}
	cout << "\n";
	for(int i = 1; i <= n; ++i){
		cout << i << ": " << level[i] << "\n";
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
