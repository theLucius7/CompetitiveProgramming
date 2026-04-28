#include <bits/stdc++.h>

using i64 = long long;

using namespace std;

void solve() {
	int n;
	std::cin >> n;

	std::vector g(n, std::vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> g[i][j];
		}
	}
	vector<int> ans;
	for(int i = 0 ; i < n ; i++){
		if(i % 2 == 0){
			for(int j = 0 ; j< n ; j++){
				ans.push_back(g[i][j]);
			}
		}else{
			for(int j = n-1 ; j>=0 ; j--){
				ans.push_back(g[i][j]);
			}
		}
	}
	int cnt = 0;
	for(int i = 1 ; i< n*n ; i++){
		if(ans[i-1] < ans[i]){
			cnt++;
		}
	}
	if(cnt <= n*n-1 - cnt){
		for(int i = 0 ; i< n*n ; i++){
			cout << ans[i] << " \n"[i == n * n - 1];
		}
	} else {
		for (int i = n * n - 1; i >= 0; i--) {
			std::cout << ans[i] << " \n"[i == 0];
		}
	}
}

int main() {
	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}