#include <bits/stdc++.h>

using i64 = long long;

using namespace std;

#define int long long


signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<int> A(7);
	std::map<int, int> cnt;
	for (int i = 0; i < 7; i++) {
		std::cin >> A[i];
		cnt[A[i]]++;
	}

	int cntx = 0, cnty = 0;
	for (auto [k, v] : cnt) {
		if (v >= 3) {
			cntx++;
		}
		if (v >= 2) {
			cnty++;
		}
	}

	cnty -= cntx;

	std::cout << ((cntx >= 2 || (cntx >= 1 && cnty >= 1)) ? "Yes" : "No") << "\n"; 


	return 0;
}