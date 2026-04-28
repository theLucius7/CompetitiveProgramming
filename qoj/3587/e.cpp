#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::vector<std::string> s(2);
	std::cin >> n >> s[0] >> s[1];

	int p;
	std::cin >> p;

	std::vector<int> cntLo(2), cntHi(2);
	for (int i = 1; i <= n; i++) {
		if (i < p) {
			cntLo[0] += s[0][i - 1] == '1';
			cntLo[1] += s[1][i - 1] == '1';
		} else {
			cntHi[0] += s[0][i - 1] == '1';
			cntHi[1] += s[1][i - 1] == '1';
		}
	}

	if (cntLo[1] <= 1) {
		for (int i = 1; i <= n; i++) {
			if (s[0][i - 1] == '2') {
				for(int j = i + 1; j <= n; j++) {
					if (s[1][j - 1] == '2') {
						std::cout << "Yes\n";
						return;
					}
				}
			}
		}


		for (int i = 1; i <= n; i++) {
			if (s[0][i - 1] == '1') {
				for (int j = i + 1; j <= n; j++) {
					if (s[1][j - 1] == '1') {
						if (j >= p || (j < p && cntLo[1] == 0)) {
							std::cout << "Yes\n";
							return;
						} else {
							bool success = true;
							for (auto c : s[]) {
								if (c == '2') {
									success = false;
									break;
								}
							}
							if (success) {
								std::cout << "Yes\n";
								return;
							}
						}
					}
				}
				break;
			}
		}
	}

	int cnt = 0;
	for (int j = 1; j <= n; j++) {
		if (s[1][j - 1] == '2') {
			for (int i = j + 1; i <= n; i++) {
				if (s[0][i - 1] == '2') {
					s[0][i - 1] = '0';
					s[1][j - 1] = '0';
					cnt++;
					break;
				}
			}
		}
	}

	if (cntLo[0] <= 1) {
		std::cout << "Yes\n";
		return;
	}

	for (int i = 1; i < p; i++) {
		if (s[0][i - 1] == '1') {
			bool ok = false;
			if (cnt) {
				for (int j = n; j >= p; j--) {
					if (s[1][j - 1] == '1') {
						s[1][j - 1] = '0';
						cnt--;
						ok = true;
						break;
					}
				}
			} else {
				for (int j = p; j <= n; j++) {
					if (s[1][j - 1] == '1') {
						s[1][j - 1] = '0';
						for (int ni = j + 1; ni <= n; ni++) {
							if (s[0][ni - 1] == '1') {
								s[0][ni - 1] = '0';
								ok = true;
								break;
							}
						}
						break;
					}
				}
			}

			if (!ok) {
				std::cout << "No\n";
				return;
			}

			cntLo[0]--;
			if (cntLo[0] == 1) {
				std::cout << "Yes\n";
				return;
			}
		}
	}


	std::cout << "Yes\n";
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