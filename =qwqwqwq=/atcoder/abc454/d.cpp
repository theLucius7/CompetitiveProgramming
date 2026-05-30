#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	std::string A, B;
	std::cin >> A >> B;

	std::vector<char> stka, stkb;
	for (int i = 0; i < A.size(); i++) {
		if (A[i] == '(') {
			stka.push_back('(');
		} else if (A[i] == 'x') {
			stka.push_back('x');
		} else {
			if (stka.size() >= 3 && stka.end()[-1] == 'x' && stka.end()[-2] == 'x' && stka.end()[-3] == '(') {
				stka.pop_back();
				stka.pop_back();
				stka.pop_back();
				stka.push_back('x');
				stka.push_back('x');
			} else {
				stka.push_back(')');
			}
		}
	}

	for (int i = 0; i < B.size(); i++) {
		if (B[i] == '(') {
			stkb.push_back('(');
		} else if (B[i] == 'x') {
			stkb.push_back('x');
		} else {
			if (stkb.size() >= 3 &&stkb.end()[-1] == 'x' && stkb.end()[-2] == 'x' && stkb.end()[-3] == '(') {
				stkb.pop_back();
				stkb.pop_back();
				stkb.pop_back();
				stkb.push_back('x');
				stkb.push_back('x');
			} else {
				stkb.push_back(')');
			}
		}
	}

	std::cout << (stka == stkb ? "Yes" : "No") << "\n";
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