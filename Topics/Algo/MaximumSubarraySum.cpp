#include<bits/stdc++.h>
using namespace std;
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	long long n; cin >> n;
	vector<long long> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}
	long long ans = LLONG_MIN;
	long long max_so_far = 0; // max subarray sum ending at i
	for(int i = 0; i < n; ++i){
		max_so_far = max(v[i], v[i] + max_so_far);
		ans = max(ans, max_so_far);
	}
	cout << ans << "\n";
 
	return 0;
}
