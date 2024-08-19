#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;

ll f(ll i, ll j, vector<bool>& vis, vector<vector<ll>>& v, vector<vector<ll>>& dp){
    if(dp[i][j] != -1) return dp[i][j];
    dp[i][j] = inf;
    for(int u: v[i]){
        dp[i][j] = min(dp[i][j], 1 + f(u, j));
    }
    dp[i][j] = dp[j][i];
    return dp[i][j];
}

void solve(){
    ll n; cin >> n;
    vector<vector<ll>> v(n+1);
    vector<vector<ll>> dp(n+1, vector<ll>(n+1, -1));
    cin.ignore();
    for(int x = 1; x <= n; ++x){
        string s;
        getline(cin, s);
        vector<int> a;
        for(int i = 0; i < s.size(); ++i){
            string t;
            while(i < n and s[i] >= '0' and s[i] <= '9'){
                t.push_back(s[i]);
                ++i;
            }
            int num = stoi(t);
            a.push_back(num);
        }
        for(int i = 0; i < a.size(); ++i){
            v[i].push_back(a[i]);
            a[i].push_back(v[i]);
            dp[a[i]][v[i]] = 1;
            dp[v[i]][a[i]] = 1;
        }
    }
    map<ll,vector<ll>> mp;
    for(int i = 1; i <= n; ++i){
        for(int j = i+1; j <= n; ++j){
            vector<bool> vis(n+1);
            ll cnt = f(i, j, vis, v, dp);
            mp[i].push_back(cnt);
            mp[j].push_back(cnt);
        }
    }
    vector<ll,ld> each;
    for(int i = 1; i <= n; ++i){
        ld sum = 0;
        for(auto it: mp){
            sum += it.second;
        }
        
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc; cin >> tc;
    while(tc--)
        solve();
    
    return 0;
}
