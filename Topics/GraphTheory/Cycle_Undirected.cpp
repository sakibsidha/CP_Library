class Graph{
public:
	template <typename T>
	bool isCycle(T n, vector<T> g[]){
    // 1 indexing
		T par[n+1];
		bool vis[n+1] = {true};
		par[1] = -1;
		function<bool(T)> dfs = [&] (T node){
			vis[node] = true;
			for(auto child: g[node]){
				if(!vis[child]){
					par[child] = node;
					if(dfs(child)) return true;
				}
				else{
					if(par[node] != child) return true;
				}
			}
			return false;
		};
		for(int i = 1; i <= n; ++i){
			if(!vis[i]){
				bool res = dfs(i);
				if(res==true) return true;
			}
		}
		return false;
	}
};
