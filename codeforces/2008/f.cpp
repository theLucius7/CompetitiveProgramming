#include <bits/stdc++.h>

using i64 = long long;
using i128 = __int128;

constexpr int P = 1E9 + 7;

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

i64 power(int a, i64 b, int p) {
    i64 res = 1;
    for (; b; b /= 2, a = 1LL * a * a % p) {
        if (b % 2) {
            res = 1LL * res * a % p;
        }
    }
    return res;
}

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	i64 sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		sum %= P;
	}

	i128 res = 0;
	for (int i = 0; i < n; i++) {
		res += ((i128)a[i] * sum) - ((i128)a[i] * a[i]);
		res %= P;
		res += P;
		res %= P;
	}
	res *= power(n, P - 2, P);
	res %= P;
	res *= power(n - 1, P - 2, P);
	res %= P;
	std::cout << res << "\n";
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