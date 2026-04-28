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

i128 exgcd(i128 a, i128 b, i128 &x, i128 &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    i128 g = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}

void solve() {
	i64 S, a, b;
	std::cin >> S >> a >> b;

	i128 x, y;
	i128 g = exgcd(a, b, x, y);
	if (S % g != 0) {
		std::cout << "No\n";
		return;
	}


	x *= S / g, y *= S / g;
	i128 cx = b / g, cy = a / g;


	auto calc = [&](i128 k) {
		i128 nx = x + k * cx, ny = y - k * cy;
		return std::max(nx, ny);
	};

	i128 le = (-x >= 0 ? (-x + cx - 1) / cx : -x / cx), ri = (y >= 0 ? y / cy : (y - cy + 1) / cy);
	while (ri - le > 2) {
		i128 m1 = le + (ri - le) / 3, m2 = ri - (ri - le) / 3;
		if (calc(m1) < calc(m2)) {
			ri = m2;
		} else {
			le = m1;
		}
	}

	i128 min = LLONG_MAX;
	std::pair<i128, i128> ans;
	for (i128 k = le; k <= ri; k++) {
		i128 nx = x + k * cx, ny = y - k * cy;
		if (nx < 0 || ny < 0) {
			continue;
		}
		if (std::max(nx, ny) < min) {
			min = std::max(nx, ny);
			ans = {nx, ny};
		}
	}

	if (min == LLONG_MAX) {
		std::cout << "No\n";
		return;
	}


	std::cout << "Yes\n";
	std::cout << ans.first << " " << ans.second << "\n";

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