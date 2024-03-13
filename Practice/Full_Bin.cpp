#include <bits/stdc++.h>
using namespace std;

int n, mx = 0, capacity;
vector<bool> taken;
vector<int> ans;

bool done(){
	for(int i = 0; i < n; ++i){
		if(taken[i]==false){
			return false;
		}
	}
	return true;
}

void BT(vector<int>& groups, vector<int>& cur, int idx, int sum){
	if(idx==n){
		if(sum > mx){
			mx = sum;
			ans = cur; // store the current subset, that gave the best maximum, to ans.
		}
		return;
	}
	if(taken[idx]==false){ // if the group is not taken yet
		if(sum + groups[idx] <= capacity){
			// take
			cur.push_back(idx);
			BT(groups, cur, idx + 1, sum + groups[idx]);
			cur.pop_back();
			
			// not take
			BT(groups, cur, idx + 1, sum);
		}
		else BT(groups, cur, idx + 1, sum);
	}
	else BT(groups, cur, idx+1, sum);
}

void solve(){
	cin >> n;
	vector<int> groups(n);
	for(int i = 0; i < n; ++i){
		cin >> groups[i];
	}
	cin >> capacity;
	vector<int> bus(n); // taking n buses initially.
	taken.resize(n);
	for(int i = 0; i < n; ++i){
		vector<int> cur;
		/* the backtrack funtion will set "mx" to the maximum possible subset sum
		   that is less than or equal to capacity, while ans store the subset for which
		   this happens. */
		BT(groups, cur, 0, 0);
		bus[i] = mx;
		mx = 0;
		for(int j = 0; j < ans.size(); ++j){
			taken[ans[j]] = true; // marking all the groups that has been put in the bus already.
		}
		if(done()==true){
			break; // checking if all the groups are marked, if so, we reached the end then.
		} 
	}
	cout << "Buses: ";
	for(int i = 0; i < n; ++i){
		cout << bus[i] << " ";
	}
	cout << "\n";
	int cnt = 0, waste = 0;
	for(int i = 0; i < n; ++i){
		if(bus[i]==0) break;
		else{
			cnt++;
			waste += (capacity - bus[i]);
		}
	}
	cout << "Total Bus required: " << cnt << "\n";
	cout << "Total waste: " << waste << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	solve();

	return 0;
}
