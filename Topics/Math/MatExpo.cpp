#include <bits/stdc++.h>
using namespace std;
//#include "debug.h"

const int MOD = 1e9+7;

class matExpo{
public:
	template <typename T> 
	vector<vector<T>> matMult(vector<vector<T>> A, vector<vector<T>> B){
		vector<vector<T>> C(A.size(), vector<T>(B[0].size(), 0));
		for(int i = 0; i < A.size(); ++i){
			for(int j = 0; j < B.size(); ++j){
				for(int k = 0; k < B.size(); ++k){
					C[i][j] += A[i][k] * B[k][j];
				}
			}
		}
		return C;
	}
};

void solve(){
	matExpo obito;
	vector<vector<int>> A(3, vector<int>(2, 0));
	vector<vector<int>> B(2, vector<int>(2, 0));
	for(int i = 0; i < A.size(); ++i){
		for(int j = 0; j < A[0].size(); ++j){
			cin >> A[i][j];
		}
	}
	for(int i = 0; i < B.size(); ++i){
		for(int j = 0; j < B[0].size(); ++j){
			cin >> B[i][j];
		}
	}
	//debug() << db(A) << db(B);
	vector<vector<int>> ans = obito.matMult(A,B);
	//debug() << db(ans);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	// int tc; cin >> tc;
	// while(tc--)
		solve();

	return 0;
}
