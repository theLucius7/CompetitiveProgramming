#include <bits/stdc++.h>

using i64 = long long;

using i128 = __int128;
 
std::ostream &operator<<(std::ostream &os, i128 n) {
    if (n == 0) {
        return os << 0;
    }
    std::string s;
    while (n > 0) {
        s += char('0' + n % 10);
        n /= 10;
    }
    std::reverse(s.begin(), s.end());
    return os << s;
}
 
i128 toi128(const std::string &s) {
    i128 n = 0;
    for (auto c : s) {
        n = n * 10 + (c - '0');
    }
    return n;
}
 
i128 sqrti128(i128 n) {
    i128 lo = 0, hi = 1E16;
    while (lo < hi) {
        i128 x = (lo + hi + 1) / 2;
        if (x * x <= n) {
            lo = x;
        } else {
            hi = x - 1;
        }
    }
    return lo;
}

i128 gcd(i128 a, i128 b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int k;
	std::cin >> k;

	auto calc = [&](i64 x, i64 y) {
		std::deque<i64> X, Y;
		for (int i = 0; i < k; i++) {
			X.push_front(x % 3);
			x /= 3;
		}
		for (int i = 0; i < k; i++) {
			Y.push_front(y % 3);
			y /= 3;
		}

		// std::cout << "(";
		// for (int i = 0; i < k; i++) {
		// 	std::cout << X[i];
		// }
		// std::cout << ", ";
		// for (int i = 0; i < k; i++) {
		// 	std::cout << Y[i];
		// }
		// std::cout << ")\n";

		i128 res = 0;
		bool fx = false, fy = false;
		for (int i = 0; i < k; i++) {
			i64 nx, ny;
			if (fx) {
				nx = 2 - X[i];
			} else {
				nx = X[i];
			}
			if (fy) {
				ny = 2 - Y[i];
			} else {
				ny = Y[i];
			}
			fx ^= (Y[i] % 2 == 1), fy ^= (X[i] % 2 == 1);
			res = res * 9 + nx * 3 + (nx % 2 ? 2 - ny : ny);

		}


		// std::cout << res << "\n";
		return res;
	};

	std::pair<i64, i64> a, b;
	std::cin >> a.first >> a.second >> b.first >> b.second;
	i128 ans = calc(a.first, a.second) - calc(b.first, b.second);
	if (ans < 0) {
		ans *= -1;
	}
	std::cout << ans << "\n";

	return 0;
}