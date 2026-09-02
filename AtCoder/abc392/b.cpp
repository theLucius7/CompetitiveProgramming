#include <bits/stdc++.h>

using i64 = long long;

#define int long long

constexpr int inf = 1E18;

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, M;
	std::cin >> N >> M;

	std::vector<int> A(M);
	for (int i = 0; i < M; i++) {
		std::cin >> A[i];
	}

	std::set<int> set;
	for (int i = 1; i <= N; i++) {
		set.insert(i);
	}

	for (int i = 0; i < M; i++) {
		set.erase(set.find(A[i]));
	}

	std::cout << set.size() << "\n";
	for (auto x : set) {
		std::cout << x << " ";
	}

	return 0;
}