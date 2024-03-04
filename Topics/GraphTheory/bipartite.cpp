template <typename T>
	bool isBipartite(vector<T> g[], T n){
		T color[n+1] = {0};
		for(int i = 1; i <= n; ++i){
			if(!color[i]){
				T source = i;
				color[source] = 1;
				queue<T> q;
				q.push(source);
				while(!q.empty()){
					T node = q.front();
					q.pop();
					for(auto it: g[node]){
						if(!color[it]){
							color[it] = (color[node]==1) ? 2 : 1;
							q.push(it);
						}
						if(color[it] == color[node]) return false;
					}
				}
			}
		}
		return true;
	}
