#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::string S, T;
	std::cin >> S >> T;
	S += "..";
	T += "..";

	std::queue<std::string> q;
	std::map<std::string, int> cnt;
	q.push(S);
	cnt[S] = 0;

	while (q.size()) {
		auto t = q.front();
		int c = cnt[t];
		q.pop();

		if (t == T) {
			std::cout << c << "\n";
			return 0;
		}

		int it = t.find("..");
		for (int i = 0; i < N + 1; i++) {
			if (std::abs(it - i) >= 2) {
				auto nt = t;
				std::swap(nt[i], nt[it]);
				std::swap(nt[i + 1], nt[it + 1]);

				if (!cnt.contains(nt)) {
					q.push(nt);
					cnt[nt] = c + 1;
				}
			}
		}
	}

	std::cout << -1 << "\n";
	

	return 0;
}