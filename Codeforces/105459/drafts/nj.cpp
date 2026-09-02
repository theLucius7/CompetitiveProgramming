#include <bits/stdc++.h>

using i64 = long long;

using namespace std;
void solve(){
	int n, m;
	std::cin >> n >> m;
	std::vector<int>a(n);
	std::vector<std::array<int, 2>>c(m);
	for(int i = 0; i < n; i++){
		std::cin >> a[i];
	}
	for(int i = 0; i < m; i++){
		std::cin >> c[i][0] >> c[1][1];
	};
	i64 sum = std::accumulate(a.begin(), a.end(), 0ll);
	
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int T = 1;
	std::cin >> T;
	while(T--){
		solve();
	}

	return 0;
}