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

void solve() {
	i64 M;
	std::cin >> M;

	for (int i = 1; i <= 4E4 + 10; i++) {
		i128 lcm = i, cur = i + 1;
		while (M % lcm == 0) {
			if (lcm == M) {
				if (cur == i + 1) {
					break;
				}
				std::cout << i << " " << cur - 1 << "\n";

				return;
			}
			lcm = lcm * cur / gcd(lcm, cur);

			if (lcm > M) {
				break;
			}

			cur++;
		}
	}

	i64 lo = 0, hi = 1E6 + 10;
	while (lo < hi) {
		int m = (lo + hi) / 2;
		int x = 2 * m + 1;
		if ((i128)1 * x * (x + 1) * (x + 2) >= M) {
			hi = m;
		} else {
			lo = m + 1;
		}
	}

	int x = 2 * lo + 1;
	if ((i128)1 * x * (x + 1) * (x + 2) == M) {
		std::cout << x << " " << x + 2 << "\n";
		return;
	}

	lo = 0, hi = 3E6 + 10;
	while (lo < hi) {
		int m = (lo + hi) / 2;
		int x = 2 * m;
		if ((i128)1 * x * (x + 1) * (x + 2) / 2 >= M) {
			hi = m;
		} else {
			lo = m + 1;
		}
	}
	x = 2 * lo;
	if ((i128)1 * x * (x + 1) * (x + 2) / 2 == M) {
		std::cout << x << " " << x + 2 << "\n";
		return;
	}

	lo = 0, hi = 2E9 + 10;
	while (lo < hi) {
		i64 m = (lo + hi) / 2;
		if ((i128)m * (m + 1) >= M) {
			hi = m;
		} else {
			lo = m + 1;
		}
	}
	if ((i128)1 * lo * (lo + 1) == (i128)M) {
		std::cout << lo << " " << lo + 1 << "\n";
		return;
	}

	std::cout << "NIE\n";
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