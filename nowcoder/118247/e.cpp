#include <bits/stdc++.h>

constexpr int P = 998244353;

using i64 = long long;

int norm(int x) {
    if (x < 0) {
        x += P;
    }
    if (x >= P) {
        x -= P;
    }
    return x;
}
template<class T>
T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
struct Z {
    int x;
    Z(int x = 0) : x(norm(x)) {}
    Z(i64 x) : x(norm(x % P)) {}
    int val() const {
        return x;
    }
    Z operator-() const {
        return Z(norm(P - x));
    }
    Z inv() const {
        assert(x != 0);
        return power(*this, P - 2);
    }
    Z &operator*=(const Z &rhs) {
        x = i64(x) * rhs.x % P;
        return *this;
    }
    Z &operator+=(const Z &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    Z &operator-=(const Z &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    Z &operator/=(const Z &rhs) {
        return *this *= rhs.inv();
    }
    friend Z operator*(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res *= rhs;
        return res;
    }
    friend Z operator+(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res += rhs;
        return res;
    }
    friend Z operator-(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res -= rhs;
        return res;
    }
    friend Z operator/(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, Z &a) {
        i64 v;
        is >> v;
        a = Z(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Z &a) {
        return os << a.val();
    }
};

std::vector<Z> p2(2E5 + 10);

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n);
	int max = 0;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		max = std::max(max, a[i]);
	}

	std::vector<int> p(max + 1);
	for (int i = 0; i < n; i++) {
		p[a[i]]++;
	}

	std::vector<int> cnt(max + 1);
	for (int x = 1; x <= max; x++) {
		int sum = 0;
		for (int y = x; y <= max; y += x) {
			sum += p[y];
		}
		cnt[x] = sum;
	}

	std::vector<Z> within(max + 1);
	for (int x = max; x >= 1; x--) {
		Z sum = 0;
		for (int y = 2 * x; y <= max; y += x) {
			sum += within[y];
		}
		within[x] = (p2[cnt[x]] - 1) - sum;
	}

	Z ans = 0;
	for (int x = 1; x <= max; x++) {
		Z s = p2[cnt[x] - p[x]] - 1;
		for (int y = 2 * x; y <= max; y += x) {
			s -= within[y];
		}
		ans += s;
	}

	std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    p2[0] = 1;
    for (int i = 1; i < 2E5 + 10; i++) {
    	p2[i] = 2 * p2[i - 1];
    }

    int t;
    std::cin >> t;

    while (t--) {
    	solve();
    }

    return 0;
}
