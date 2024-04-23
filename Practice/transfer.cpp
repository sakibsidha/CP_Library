#include <bits/stdc++.h>
using namespace std;
#include "debug.h"

void solve(){
	int n; cin >> n;
	int a[n][n];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < n; ++i){
		for(int j = i + 1; j < n; ++j){
			int f = 0;
			for(int k = 0; k < n; ++k){
				if(k == i || k == j) continue;
				else{
					// debug() << db(i) << db(j) << db(k);
					cout << "hi";
					if(a[i][k] + a[k][j] == a[i][j]){
						f = 1;
						break;
					}
				}
			}
			if(f == 0){
				cout << i + 1 << " " << j + 1 << "\n";
			}
		}
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
