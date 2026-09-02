#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int H, W, N;
	std::cin >> H >> W >> N;

	std::vector<std::array<int, 3>> a(N);
	for (int i = 0; i < N; i++) {
		std::cin >> a[i][0] >> a[i][1];
		a[i][2] = i;
	}
	std::vector<std::array<int, 3>> b = a;

	std::sort(a.begin(), a.end(), std::greater<>());
	std::sort(b.begin(), b.end(), [&](auto x, auto y) {
		auto [ah, aw, aid] = x;
		auto [bh, bw, bid] = y;
		return aw > bw;
	});


	std::vector<bool> vis(N);
	std::vector<std::pair<int, int>> ans(N);
	int la = 0, lb = 0;
	int x = 1, y = 1;
	for (int i = 0; i < N; i++) {
		while (la < N && vis[a[la][2]]) {
			la++;
		}
		while (lb < N && vis[b[lb][2]]) {
			lb++;
		}

		if (a[la][0] == H) {
			ans[a[la][2]] = {x, y};
			W -= a[la][1];
			y += a[la][1];
			vis[a[la][2]] = true;
			la++;
		} else {
			ans[b[lb][2]] = {x, y};
			H -= b[lb][0];
			x += b[lb][0];
			vis[b[lb][2]] = true;
			lb++;
		}
	}

	for (int i = 0; i < N; i++) {
		std::cout << ans[i].first << " " << ans[i].second << "\n";
	}

	return 0;
}