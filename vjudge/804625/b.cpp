#include <bits/stdc++.h>

using namespace std;
const int N = 2e5+10;

#define int long long


void solve(){
	int p, a, b, c;
	std::cin >> p >> a >> b >> c;

	std::cout << (b == 0 && c != 0 ? "No" : "Yes") << "\n";
}
signed main(){
	int T;
	T = 1;
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}