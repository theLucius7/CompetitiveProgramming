#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string X, Y;
	std::cin >> X >> Y;

	std::vector<std::string> s(2);
	s[0] = X, s[1] = Y;

	int N = 2;
	std::vector<i64> len;
	len.push_back(0);
	len.push_back(X.size());
	len.push_back(Y.size());
	for ( ; ; ) {
		len.push_back(len.back() + len[len.size() - 2]);
		N++;
		if (len.back() > 1E18) {
			break;
		}
	}

	std::vector<std::array<i64, 26>> cnt(N + 5);

	for (int i = 0; i < X.size(); i++) {
		cnt[1][X[i] - 'a']++;
	}
	for (int i = 0; i < Y.size(); i++) {
		cnt[2][Y[i] - 'a']++;
	}

	for (int i = 3; i <= N; i++) {
		for (int j = 0; j < 26; j++) {
			cnt[i][j] = cnt[i - 1][j] + cnt[i - 2][j];
		}
	}

	auto calc = [&](auto self, int id, i64 x, int c) -> i64 {
		if (id == 1 || id == 2) {
			i64 u = 0;
			for (int i = 0; i < x; i++) {
				if (s[id - 1][i] - 'a' == c) {
					u++;
				}
			}
			return u;
		}

		if (x > len[id - 1]) {
			return cnt[id - 1][c] + self(self, id - 2, x - len[id - 1], c);
		} else if (x < len[id]) {
			return self(self, id - 1, x, c);
		} else {
			return cnt[id][c];
		}
	};

	int Q;
	std::cin >> Q;

	while (Q--) {
		i64 L, R;
		char C;
		std::cin >> L >> R >> C;
		std::cout << calc(calc, N, R, C - 'a') - calc(calc, N, L - 1, C - 'a') << "\n";
	}

	return 0;
}

// a b ba bab babba babbabab babbababbabba