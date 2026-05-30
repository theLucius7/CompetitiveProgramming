#include <bits/stdc++.h>

using i64 = long long;

using i128 = __int128;

constexpr i64 P = 998244353;

std::vector<std::array<int, 7>> dd{
	{1, 1, 1, 0, 1, 1, 1},
	{0, 0, 1, 0, 0, 1, 0}, 
	{1, 0, 1, 1, 1, 0, 1}, 
	{1, 0, 1, 1, 0, 1, 1}, 
	{0, 1, 1, 1, 0, 1, 0}, 
	{1, 1, 0, 1, 0, 1, 1}, 
	{1, 1, 0, 1, 1, 1, 1}, 
	{1, 0, 1, 0, 0, 1, 0}, 
	{1, 1, 1, 1, 1, 1, 1}, 
	{1, 1, 1, 1, 0, 1, 1}
};

i64 mul(i64 a, i64 b, i64 p) {
    i64 c = a * b - i64(1.0L * a * b / p) * p;
    c %= p;
    if (c < 0) {
        c += p;
    }
    return c;
}

i64 power(i64 a, i64 b, i64 p) {
    i64 res = 1;
    for (; b; b /= 2, a = mul(a, a, p)) {
        if (b % 2) {
            res = mul(res, a, p);
        }
    }
    return res;
}


void solve() {
	int C;
	std::cin >> C;

	std::vector<int> p(7);
	for (int i = 0; i < 7; i++) {
		std::cin >> p[i];
	}

	std::vector<int> ena(10);
	for (int x = 0; x <= 9; x++) {
		i64 px = 1;
		for (int i = 0; i < 7; i++) {
			if (dd[x][i]) {
				px = (i128)px * p[i] * power(100, P - 2, P) % P;
			} else {
				px = (i128)px * (100 - p[i]) * power(100, P - 2, P) % P;
			}
		}
		ena[x] = px;
	}

	std::vector<i64> cc(C + 1);
	for (int x = 0; x <= C; x++) {
		i64 px = 1;
		int y = x;
		for (int i = 0; i < 4; i++) {
			px = px * ena[y % 10] % P;
			y /= 10;
		}
		cc[x] = px;
	}

	i64 ans = 0;
	for (int i = 0; i <= C; i++) {
		ans += cc[i] * cc[C - i];
		ans %= P;
	}
	std::cout << ans << "\n";

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