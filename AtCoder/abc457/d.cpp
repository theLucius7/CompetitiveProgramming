#include <bits/stdc++.h>

using i64 = long long;

#define int long long

constexpr int inf = 1E18;

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

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, K;
	std::cin >> N >> K;

	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}

	auto check = [&](i128 m) {
		i128 nK = K;
		for (int i = 0; i < N; i++) {
			i128 t = std::max((i128)0, m - A[i]) / (i + 1) + (std::max((i128)0, m - A[i]) % (i + 1) != 0);
			nK -= t;

			if (nK < 0) {
				return false;
			}
		}
		return true;
	};

	i128 lo = 1, hi = 1E26+10;
	while (lo < hi) {
	    i128 m = (lo + hi + 1) / 2;
	    if (check(m)) {
	        lo = m;
	    } else {
	        hi = m - 1;
	    }
	}
	std::cout << lo << "\n";

	return 0;
}