#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string S, T;
	std::cin >> S >> T;

	std::vector<char> s, t;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] != 'A') {
			s.push_back(S[i]);
		}
	}
	for (int i = 0; i < T.size(); i++) {
		if (T[i] != 'A') {
			t.push_back(T[i]);
		}
	}

	if (s != t || s.size() - t.size() < 0 || s.size() - t.size() > 1) {
		std::cout << "-1\n";
		return 0;
	}

	std::vector<int> vs, vt;
	int cnt = 0;
	for (int i = 0; i <= S.size(); i++) {
		if (i == S.size() || S[i] != 'A') {
			vs.push_back(cnt);
			cnt = 0;
		} else {
			cnt++;
		}
	}
	for (int i = 0; i <= T.size(); i++) {
		if (i == T.size() || T[i] != 'A') {
			vt.push_back(cnt);
			cnt = 0;
		} else {
			cnt++;
		}
	}

	int res = 0;
	for (int i = 0; i < vs.size(); i++) {
		res += std::max(0, vs[i] - vt[i]);
	}
	std::cout << (res * 2 - S.size() + T.size()) << "\n";

	return 0;
}