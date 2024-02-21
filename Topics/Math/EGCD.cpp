#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// ax + by = gcd(a,b)

template <typename T>
T egcd(T a, T b, T& x, T& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    T x1, y1;
    T d = egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

void solve(){
	int x, y;
	int GCD = egcd(4,7,x,y);
	cout << "GCD of 4 and 7 is: " << GCD << endl;
	cout << "x: " << x << " & y: " << y << endl;
	
	/* if gcd(a,b) is 1, that is they are co-prime, then x will be the inverse modulo of 
	 * a in b modular field. 
	 * let,
	 * 1/a (mod m) = x     [x is the inverse modulo of a]
	 * =>  ax = 1 (mod m) 
	 * => ax + my = 1 (mod m)
	*/
	
	cout << "Inverse Modulo of 4 in 7 mod field: " << x << endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	//int tc; cin >> tc;
	//while(tc--)
		solve();

	return 0;
}
