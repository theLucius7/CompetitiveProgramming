#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, a, b;
	std::cin >> n >> a >> b;


	std::vector<bool> st(30);
	std::vector<int> cnt(30);

	int s;
	std::cin >> s;

	int pen = 0, ac = 0;
	std::vector<std::pair<int, int>> unk;

	while (s--) {
		int t;
		std::cin >> t;

		char p;
		std::cin >> p;
		int x = p - 'A';

		std::string v;
		std::cin >> v;

		if (t < 240) {
			if (v == "ac") {
				if (!st[x]) {
					pen += t + 20 * cnt[x];
					ac++;
					st[x] = true;
				}
			} else if (v == "rj") {
				if (!st[x]) {
					cnt[x]++;
				}
			}
		} else {
			if (!st[x]) {
				unk.push_back({t + cnt[x] * 20, x});
				st[x] = true;
			}
		}
	}
	if (ac > a || (ac == a && pen < b)) {
		std::cout << 0 << "\n";
		return;
	}

	std::sort(unk.begin(), unk.end());

	i64 sum = 0;
	for (int i = 0; i < unk.size(); i++) {
		sum += unk[i].first;
	}

	if (ac + unk.size() < a) {
		std::cout << "-1\n";
		return;
	}
	if (ac + unk.size() == a && sum + pen >= b) {
		std::cout << "-1\n";
		return;
	}

	if (ac + unk.size() == a) {
		std::cout << unk.size() << "\n";
		return;
	}

	i64 suma = 0;
	for (int i = 0; i < a - ac; i++) {
		suma += unk[i].first;
	}

	// std::cout << suma << " " << pen << "\n";
	if (suma + pen < b) {
		std::cout << a - ac << "\n";
		return;
	}

	std::cout << a - ac + 1 << "\n";

	// std::cout << ac << " " << pen << "\n";
	// for (int i = 0; i < unk.size(); i++) {
	// 	std::cout << unk[i].first << " " << unk[i].second << " \n"[i == unk.size() - 1];
	// }
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}