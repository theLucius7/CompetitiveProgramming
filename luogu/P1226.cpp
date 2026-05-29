#include <bits/stdc++.h>

using int64 = long long;

constexpr int64 binpow(int64 a, int64 b, int64 p) {
    int64 res = 1;
    for (a %= p; b; b /= 2, a = (a * a) % p) {
        if (b % 2) {
            res = (res * a) % p;
        }
    }
    return res;
}

constexpr int64 mul(int64 a, int64 b, int64 p) {
    int64 res = a * b - int64(1.L * a * b / p) * p;
    res %= p;
    if (res < 0) {
        res += p;
    }
    return res;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int64 a, b;
	int p;

	std::cin >> a >> b >> p;

	std::cout << a << "^" << b << " mod " << p << "=" << binpow(a, b, p) << "\n";


	return 0;
}