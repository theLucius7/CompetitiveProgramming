#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<i64> A(n);
	std::multiset<i64> s;
	for (int i = 0; i < n; i++) {
		std::cin >> A[i];
		s.insert(A[i]);
	}

	i64 sum = std::accumulate(A.begin(), A.end(), 0LL);

	std::sort(A.begin(), A.end());

	auto check = [&](i64 ans, std::multiset<i64> ss) {
		while (!ss.empty()) {
			auto it = ss.begin();
			i64 x = *it;
			if (*it == ans) {
				ss.erase(it);
			} else {
				ss.erase(it);
				auto nit = ss.lower_bound(ans - x);
				if (nit == ss.end() || *nit + x != ans) {
					return false;
				}
				ss.erase(nit);
			}
		}

		return true;
	};


	std::set<i64> set;
	if (sum % A.back() == 0) {
		if (check(A.back(), s)) {
			set.insert(A.back());
		}
	} 

	if (check(A.back() + A[0], s)) {
		set.insert(A.back() + A[0]);
	}



	for (auto x : set) {
		std::cout << x << " ";
	}

	return 0;
}