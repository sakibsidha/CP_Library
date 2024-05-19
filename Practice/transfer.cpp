#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
char a[201][201];
int dp[201][201];

const int inf = 1e9;

int f(int i, int j){
  if(i%2 == 0){
		int x = 0;
		if(j + 1 < m && a[i][j + 1] != '#'){
			x = (a[i][j + 1] == 'T') ? 1 + f(i, j + 1) : f(i, j + 1);
		}
		int y = 0;
		if(i + 1 < n && a[i + 1][j] != '#'){
			y = (a[i + 1][j] == 'T') ? 1 + f(i + 1, j) : f(i + 1, j);
		}
		return dp[i][j] = max(x, y);
  }
  else{
   	int x = 0;
    if(j - 1 >= 0 && a[i][j - 1] != '#'){
    	x = (a[i][j - 1] == 'T') ? 1 + f(i, j - 1) : f(i, j - 1);
    }
    int y = 0;
    if(i + 1 < n && a[i + 1][j] != '#'){
    	y = (a[i + 1][j] == 'T') ? 1 + f(i + 1, j) : f(i + 1, j);
    }
    return dp[i][j] = max(x, y);
  }
}

void solve(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> a[i][j];
            dp[i][j] = 0;
        }
    }
    f(0, 0);
    int ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 

    int tc; cin >> tc;
    while(tc--)
        solve();

    return 0;
}
