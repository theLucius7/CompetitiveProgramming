#include <bits/stdc++.h>

using namespace std;
const int N = 2e5+10;

#define int long long


void solve(){
	int x;
	std::cin >> x;

	if (x % 2 == 1) {
		std::cout << x << "\n";
	} else {
		std::cout << (x ^ (x / 2)) << "\n";
	}
}
signed main(){
	int T;
	T = 1;
	cin >> T;
	while(T--){
		solve();
	}
}