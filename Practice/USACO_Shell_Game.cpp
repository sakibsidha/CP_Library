#include <bits/stdc++.h>
using ll = long long;

typedef struct node{
	int a, b, g;
} node;

void solve(){
	int n;
	std::cin >> n;
	std::vector<node> v(n);
	for(int i = 0; i < n; ++i){
		std::cin >> v[i].a >> v[i].b >> v[i].g;
	}
	int ans = 0;
	for(int i = 1; i <= 3; ++i){
		int cur = i, cnt = 0;
		for(int j = 0; j < n; ++j){
			if(v[j].a == cur || v[j].b == cur){
				if(v[j].a == cur) cur = v[j].b;
				else cur = v[j].a;
			}
			if(v[j].g == cur) cnt++;
		}
		ans = std::max(ans, cnt);
	}
	std::cout << ans << '\n';
}

int main(){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	
	freopen("shell.in", "r", stdin);
	freopen("shell.out", "w", stdout);
	
	//int tc; std::cin >> tc;
	//while(tc--)
		solve();
		
	return 0;
}
