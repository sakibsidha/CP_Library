#include <bits/stdc++.h>
using namespace std;

bool done(int groups[], int n){
	for(int i = 0; i < n; ++i){
		if(groups[i] != 0) return false;
	}
	return true;
}

int find_mx(int groups[], int n, int capacity){
	int mx = 0;
	for(int j = 0; j < n; ++j){
		for(int k = 0; k < n; ++k){
			if(k == j || groups[j]==0 || groups[k]==0) continue; // ignoring the combinations of group that are empty
			else{
				if(groups[j] + groups[k] <= capacity){
					mx = max(mx, groups[j] + groups[k]);
				}
			}
		}
	}
	return mx;
}

int main(){
	int n; cin >> n;
	int groups[n];
	for(int i = 0; i < n; ++i){
		cin >> groups[i];
	}
	int bus[n] = {0};
	int capacity; cin >> capacity;
	for(int i = 0; i < n; ++i){
		int mx = find_mx(groups, n, capacity); // find the maximum possible sum that we can achieve with the remaining groups
		int f = 0;
		for(int j = 0; j < n; ++j){
			if(f) break;
			for(int k = 0; k < n; ++k){
				if(k == j || groups[j]==0 || groups[k]==0) continue; // ignoring the combinations of group that are empty
				else{
					if(groups[j] + groups[k] == mx){ // we found the two groups j & k that will give us the maximum sum
						bus[i] = mx; // set the answer for current bus to mx  
						groups[j] = groups[k] = 0; // mark the j & k group as zero, we won't be using them in future combinations
						f = 1; break; // break the both loop
					}
				}
			}
		}
		if(done(groups, n)) break; // check if all groups are empty, if so, we reached the end
	}
	cout << "All buses: ";
	for(int i = 0; i < n; ++i){
		cout << bus[i] << " ";
	}
	cout << "\n";
	int cnt = 0, waste = 0;
	for(int i = 0; i < n; ++i){
		if(bus[i]==0){
			break;
		}
		else{
			waste += (capacity - bus[i]);
			cnt++;
		}
	}
	cout << "Total number of Bus required: " << cnt << "\n";
	cout << "Total waste: " << waste << "\n";
}
