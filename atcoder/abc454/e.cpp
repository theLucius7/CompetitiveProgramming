#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int N, A, B;
	std::cin >> N >> A >> B;
	A--, B--;

	if (N % 2 == 1 || (A + B) % 2 == 0) {
		std::cout << "No\n";
		return;
	}
	std::cout << "Yes\n";

	int r1 = (A % 2 ? A - 1 : A);
	int r2 = (A % 2 ? A : A + 1);

	std::vector nxt(N, std::vector<std::pair<int, int>>(N));
	std::vector<int> cnt(N);
	for (int x = r1, y = 0; x != r2 || y != N - 1; ) {
		int nx, ny;
		if (!cnt[y]) {
			nx = (x % 2 ? x - 1 : x + 1);
			ny = y;
			if (nx == A && ny == B) {
				nx = x;
				ny = y + 1;
			}
		} else {
			nx = x;
			ny = y + 1;
		}
		cnt[y]++;
		nxt[x][y] = {nx, ny};
		x = nx, y = ny;
	}

	if (r2 < N - 1) {
		nxt[r2][N - 1] = {r2 + 1, N - 1};
	}

	for (int x = 0; x < r1; x += 2) {
		for (int y = 0; y < N; y++) {
			if (y == N - 1) {
				nxt[x][y] = {x + 1, y};
			} else {
				nxt[x][y] = {x, y + 1};
			}
		}
	}
	for (int x = r2 + 2; x < N; x += 2) {
		for (int y = 0; y < N; y++) {
			if (y == N - 1) {
				nxt[x][y] = {x + 1, y};
			} else {
				nxt[x][y] = {x, y + 1};
			}
		}
	}

	for (int x = 1; x < r2; x += 2) {
		for (int y = 0; y < N; y++) {
			if (y == 0) {
				nxt[x][y] = {x + 1, y};
			} else {
				nxt[x][y] = {x, y - 1};
			}
		}
	}
	for (int x = r1 + 2; x < N; x += 2) {
		for (int y = 0; y < N; y++) {
			if (y == 0) {
				nxt[x][y] = {x + 1, y};
			} else {
				nxt[x][y] = {x, y - 1};
			}
		}
	}

	std::vector<char> ans;
	for (int x = 0, y = 0; x != N - 1 || y != N - 1; ) {
		auto [nx, ny] = nxt[x][y];
		if (nx == x + 1) {
			ans.push_back('D');
		} else if (nx == x - 1) {
			ans.push_back('U');
		} else if (ny == y + 1) {
			ans.push_back('R');
		} else {
			ans.push_back('L');
		}
		x = nx, y = ny;
	}

	for (auto c : ans) {
		std::cout << c;
	}
	std::cout << "\n";

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