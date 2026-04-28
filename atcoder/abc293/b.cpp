#include <bits/stdc++.h>

using i64 = long long;

int main () {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::vector<int> A(N);
	for (int i = 0; i < N; i ++ ) {
		std::cin >> A[i];
		A[i] -- ;
	}

	std::vector<bool> vis(N);
	for (int i = 0; i < N; i ++ ) {
		if (!vis[i]) {
			vis[A[i]] = true;
		}
	}

	std::vector<int> ans;
	for (int i = 0; i < N; i ++ ) {
		if (!vis[i]) {
			ans.push_back (i);
		}
	}

	std::cout << ans.size () << "\n";
	for (int i = 0; i < ans.size(); i ++ ) {
		std::cout << ans[i] + 1 << " \n"[i == ans.size () - 1];
	}

	return 0;
}