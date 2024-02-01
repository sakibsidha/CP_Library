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
		// identity matrix
		Matrix base = {
			{1, 0},
			{0, 1}
		};
		// matrix to be exponentiated
		Matrix mat = {
			{0, 1},
			{1, 1}
		};
		// exponentiation; base will be the answer
		for(; n; n >>= 1, mat = mult(mat, mat)){
			if(n&1) base = mult(base, mat);
		}
		// now we can keep the base values of the reccurrence in a matrix
		Matrix rec = {{0},{1}};
		Matrix ans = mult(base, rec);
		cout << ans[0][0] << endl;
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
