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

constexpr i64 P = 1E9 + 7;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::map<i128, i128> map;
	for (int i = 0; i < n; i++) {
		i64 c, w;
		std::cin >> c >> w;
		map[w] += c;
	}

	i128 ans = 0;
	while (!map.empty()) {
		auto it = map.begin();
		auto [w, c] = *it;
		map.erase(it);

		if (map.empty() && c == 1) {
			break;
		}

		i64 nc = c / 2, nw = 2 * w;
		if (nc) {
			ans += nc * nw;
			ans %= P;
			map[nw] += nc;
			c %= 2;	
		}
		
		if (c) {
			auto nit = map.begin();
			auto [wu, cu] = *nit;

			ans += c * (wu + w);
			ans %= P;

			if (cu == 1) {
				map.erase(nit);
			} else {
				map[wu]--;
			}

			map[wu + w]++;
		}
	}

	std::cout << ans << "\n";

	return 0;
}