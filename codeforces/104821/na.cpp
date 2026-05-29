#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using i64 = long long;
using i128 = __int128;
using namespace std;


using namespace std;

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

i128 mul(i128 a, i128 b, i128 p) {
    i128 c = a * b - i128(1.0L * a * b / p) * p;
    c %= p;
    if (c < 0) {
        c += p;
    }
    return c;
}

i128 power(i128 a, i128 b, i128 p) {
	if (a == 0 ) {
		return 1;
	}
	// 
    i128 res = 1;
    for (; b; b /= 2, a = mul(a, a, p)) {
        if (b % 2) {
            res = mul(res, a, p);
        }
    }
    return res;
}

void solve() {
	i64 P, m;
	std::cin >> P >> m;

	i64 t = m / P;
	i64 ans = max(0ll, t - 100);
	for (int i = max(0ll, t - 100); i <= t + 100; i ++ ) {
		if ((((i128)i * P + 1) ^ (P - 1)) <= m) {
			ans ++ ;
		}
	}
	std::cout << ans << "\n";
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}