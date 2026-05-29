#include <bits/stdc++.h>

using i64 = long long;
using real = long double;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::vector<real> v(N);
	for (int i = 0; i < N; i++) {
		std::string s;
		std::cin >> s;
		v[i] = std::stoi(s.substr(0, 2)) + 1.L * std::stoi(s.substr(3, 2)) / 60 + 1.L * std::stoi(s.substr(6, 2)) / 3600;
	}

	std::vector<int> cnt(5);
	std::cin >> cnt[0] >> cnt[2] >> cnt[3] >> cnt[4];
	cnt[1] = N - cnt[0] - cnt[2] - cnt[3] - cnt[4];

	std::cout << "\n";

	std::sort(v.begin(), v.end(), std::greater<>());

	for (int i = 0; i < N; i++) {
		if (cnt[4]) {
			v[i] /= 2.0;
			cnt[4]--;
		} else if (cnt[3]) {
			v[i] /= 1.5;
			cnt[3]--;
		} else if (cnt[2]) {
			v[i] /= 1.25;
			cnt[2]--;
		} else if (cnt[1]) {
			cnt[1]--;
		} else {
			v[i] /= 0.75;
			cnt[0]--;
		}
	}

	real t;
	std::cin >> t;

	real sum = std::accumulate(v.begin(), v.end(), 0.L);

	if (t >= sum) {
		std::cout << "Yes\n";
		std::cout << std::fixed << std::setprecision(2) << t - sum << "\n";
	} else {
		std::cout << "No\n";
		std::cout << std::fixed << std::setprecision(2) << sum - t << "\n";
	}





	return 0;
}