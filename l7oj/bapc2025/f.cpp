#include <bits/stdc++.h>

using i64 = long long;

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

using real = long double;

constexpr int inf = 1E8;

void solve1() {
	int k;
	std::cin >> k;

	int u = k / 31, v = k % 31;
	// std::cout << u << " " << v << "\n";
	for (int x = 0; x < 30; x++) {
		int y = (u * x + v) % 31;
		std::cout << (x * 31 + y + 1) << " \n"[x == 29];
	}
}

void solve2() {
	int a, b;
	std::cin >> a >> b;

	int xa = (a - 1) / 31, ya = (a - 1) % 31;
	int xb = (b - 1) / 31, yb = (b - 1) % 31;

	int u = ((ya - yb) * power(xa - xb, 29, 31) % 31 + 31) % 31;
	int v = ((ya - xa * u) % 31 + 31) % 31;
	// std::cout << u << " " << v << "\n";
	std::cout << u * 31 + v << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string t;
	std::cin >> t;

	t == "send" ? solve1() : solve2();


	return 0;
}