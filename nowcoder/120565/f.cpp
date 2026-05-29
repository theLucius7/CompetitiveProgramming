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
	i64 n, a, b;
	std::cin >> n >> a >> b;

	std::vector<i128> dp(57);
	for (int i = 0; i <= 56; i++) {
		if (i >= 2) {
			dp[i] = std::max(dp[i], dp[i - 2] + b);
		}
		if (i >= 7) {
			dp[i] = std::max(dp[i], dp[i - 7] + a);
		}
		if (i >= 8) {
			dp[i] = std::max(dp[i], dp[i - 8] + a + b);
		}
	}

	i128 ans = 0;
	for (int i = 0; i <= 56; i++) {
		if (n >= i && (n - i) % 8 == 0) {
			ans = std::max(ans, (i128)(n - i) / 8 * (a + b) + dp[i]);
		}
	}

	for (int i = 0; i <= 56; i++) {
		if (n >= i && (n - i) % 7 == 0) {
			ans = std::max(ans, (i128)(n - i) / 7 * a + dp[i]);
		}
	}

	for (int i = 0; i <= 56; i++) {
		if (n >= i && (n - i) % 2 == 0) {
			ans = std::max(ans, (i128)(n - i) / 2 * b + dp[i]);
		}
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