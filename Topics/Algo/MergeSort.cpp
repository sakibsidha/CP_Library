#include<bits/stdc++.h>
using namespace std;

int n; 

void merge(int a[], int l, int mid, int r){
	vector<int> left, right;
	for(int i = l; i <= mid; ++i) left.push_back(a[i]);
	for(int i = mid+1; i <= r; ++i) right.push_back(a[i]);
	vector<int> final;
	int it_l = 0, it_r = 0;
	while(it_l < left.size() && it_r < right.size()){
		if(left[it_l] <= right[it_r]){
			final.push_back(left[it_l]);
			it_l++;
		}
		else{
			final.push_back(right[it_r]);
			it_r++;
		}
	}
	if(it_l < left.size()){
		while(it_l < left.size()){
			final.push_back(left[it_l]);
			it_l++;
		}
	}
	if(it_r < right.size()){
		while(it_r < right.size()){
			final.push_back(right[it_r]);
			it_r++;
		}
	}
	int idx = 0;
	for(int i = l; i <= r; ++i){
		a[i] = final[idx];
		idx++;
	}
}

void merge_sort(int a[], int l, int r){
	if(l >= r) return; 
	int mid = (l+r)/2;
	merge_sort(a, l, mid);
	merge_sort(a, mid + 1, r);
	merge(a, l, mid, r);
}

int main(){
	cin >> n;
	int a[n];
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	merge_sort(a, 0, n-1);
	cout << "Sorted array: ";
	for(int i = 0; i < n; ++i){
		cout << a[i] << " ";
	}
	cout << "\n";
}
