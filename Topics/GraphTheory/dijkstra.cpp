#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int inf = 1e9;

void solve(){
    int n, m; cin >> n >> m;
    vector<pair<ll,ll>> g[n+1];
    for(int i = 0; i < m; ++i){
        int x, y, w; cin >> x >> y >> w;
        g[x].push_back({y,w});
        g[y].push_back({x,w});
    }
    int source = 1;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0,source});
    int dist[n+1]{};
    for(int i = 2; i <= n; ++i){
        dist[i] = inf;
    }
    while(!q.empty()){
        pair<int,int> p = q.top();
        int v = p.second;
        q.pop();
        for(auto it: g[v]){
            int u = it.first, cost = it.second;
            if(dist[u] > cost + dist[v]){
                q.push({cost + dist[v], u});
                dist[u] = cost + dist[v];
            }
        }
        
    }
    for(int i = 1; i <= n; ++i){
        cout << i << ": " << dist[i] << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //int tc; cin >> tc;
    //while(tc--)
        solve();

    return 0;
}
