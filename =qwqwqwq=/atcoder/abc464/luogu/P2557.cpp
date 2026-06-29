#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1000;

struct BigInt {
    int a[N];
    BigInt(int x = 0) : a{} {
        for (int i = 0; x; i++) {
            a[i] = x % 10;
            x /= 10;
        }
    }
    BigInt &operator*=(int x) {
        for (int i = 0; i < N; i++) {
            a[i] *= x;
        }
        for (int i = 0; i < N - 1; i++) {
            a[i + 1] += a[i] / 10;
            a[i] %= 10;
        }
        return *this;
    }
    BigInt &operator/=(int x) {
        for (int i = N - 1; i >= 0; i--) {
            if (i) {
                a[i - 1] += a[i] % x * 10;
            }
            a[i] /= x;
        }
        return *this;
    }
    BigInt &operator+=(const BigInt &x) {
        for (int i = 0; i < N; i++) {
            a[i] += x.a[i];
            if (a[i] >= 10) {
                a[i + 1] += 1;
                a[i] -= 10;
            }
        }
        return *this;
    }

    BigInt &operator*=(const BigInt &b) {
        BigInt res;
        for (int i = 0; i < N; i++) {
            if (a[i] == 0) continue;
            for (int j = 0; i + j < N; j++) {
                res.a[i + j] += a[i] * b.a[j];
            }
        }
        for (int i = 0; i < N - 1; i++) {
            if (res.a[i] >= 10) {
                res.a[i + 1] += res.a[i] / 10;
                res.a[i] %= 10;
            }
        }
        *this = res;
        return *this;
    }
};

std::ostream &operator<<(std::ostream &o, const BigInt &a) {
    int t = N - 1;
    while (a.a[t] == 0) {
        t--;
    }
    for (int i = t; i >= 0; i--) {
        o << a.a[i];
    }
    return o;
}

i64 power(i64 a, i64 b) {
    i64 res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	i64 n;
	int k;
	std::cin >> n >> k;

	std::vector<std::pair<i64, int>> pc;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			int cnt = 0;
			while (n % i == 0) {
				cnt++;
				n /= i;
			}
			pc.emplace_back(i, cnt * k);
		}
	}
	if (n != 1) {
		pc.emplace_back(n, k);
	}

	BigInt ans = 1;
	for (int i = 0; i < pc.size(); i++) {
		BigInt x = 1;
		BigInt res = 0;
		for (int j = 0; j <= pc[i].second; j++) {
			res += x;
			x *= pc[i].first;
		}
		ans *= res;
	}
	std::cout << ans << "\n";

	return 0;
}