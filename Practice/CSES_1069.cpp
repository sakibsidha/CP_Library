#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;
#define Matrix vector<vector<T>>
class MatExpo{
public:
	template <typename T> 
	Matrix mult(Matrix A, Matrix B){
		Matrix res(A.size(), vector<T>(B[0].size(), 0));
		for(int i = 0; i < A.size(); ++i){
			for(int j = 0; j < B[0].size(); ++j){
				for(int k = 0; k < B.size(); ++k){
					res[i][j] += A[i][k] * B[k][j];
					res[i][j] %= mod;
				}
			}
		}
		return res;
	}
	template <typename T>
	void solution(T n){
		Matrix base = {
			{1, 0, 0, 0, 0, 0},
			{0, 1, 0, 0, 0, 0},
			{0, 0, 1, 0, 0, 0},
			{0, 0, 0, 1, 0, 0},
			{0, 0, 0, 0, 1, 0},
			{0, 0, 0, 0, 0, 1}
		};
		Matrix mat = {
			{0, 1, 0, 0, 0, 0},
			{0, 0, 1, 0, 0, 0},
			{0, 0, 0, 1, 0, 0},
			{0, 0, 0, 0, 1, 0},
			{0, 0, 0, 0, 0, 1},
			{1, 1, 1, 1, 1, 1}
		};
		for(; n; n >>= 1, mat = mult(mat, mat)){
			if(n&1) base = mult(base, mat);
		}
		Matrix rec = {{0},{0},{0},{0},{0},{1}};
		Matrix ans = mult(base, rec);
		cout << ans[5][0] << endl;
	}
};

void solve(){
	long long n; cin >> n;
	MatExpo m;
	m.solution(n);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	//int tc; cin >> tc;
	//while(tc--)
		solve();

	return 0;
}
