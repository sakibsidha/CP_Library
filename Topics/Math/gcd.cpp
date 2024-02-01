#include <bits/stdc++.h>
int main() {
	function<int(int, int)> gcd = [&](int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	};
	cout << gcd(20, 30) << '\n';  // outputs 10
}
