#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 P = 998244353;
constexpr int L = 2E5;

i64 fac[L + 1];

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		std::cin >> b[i];
	}

	int min = *std::min_element(b.begin(), b.end());
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > min) {
			cnt++;
		}
	}

	std::cout << fac[cnt] * fac[n - cnt] % P << "\n";

}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	fac[0] = 1;
    for (int i = 1; i <= L; i++) {
        fac[i] = fac[i - 1] * i % P;
    }

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}


	return 0;
}