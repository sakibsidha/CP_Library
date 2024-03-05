#include <bits/stdc++.h>
using namespace std;

int partition (vector<int>& v, int l, int pivot, int r){
    while(l <= r){
        while(v[l] < pivot) l++;
        while(v[r] > pivot) r--;
        if(l <= r){
            swap(v[l], v[r]);
            l++; r--;
        }
    }
    return l;
}
void quicksort(vector<int>& v, int s, int e){
    if(s < e){
        int mid = (s+e)/2;
        int pivot = v[mid];
        int pos = partition(v, s, pivot, e);
        quicksort(v, s, pos-1);
        quicksort (v, pos,e);
    }
}
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }
    quicksort(v, 0, n-1);
    for(int i = 0; i < n; ++i){
        cout << v[i] << " ";
    }
    cout << endl;
}
