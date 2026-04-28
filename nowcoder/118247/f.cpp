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


void solve() {
	int n;
	std::cin >> n;

	std::vector<int> v(n);
	for (int i = 0; i < n; i++) {
		std::string s;
		std::cin >> s;

		int sum = 0;
		for (int j = 0; j < s.size(); j++) {
			sum += (s[j] == '(' ? 1 : -1);
		}
		v[i] = sum;
	}

	std::sort(v.begin(), v.end());

	Z ans = 0;
	std::vector<bool> vis(n);
	auto dfs = [&](auto self, int cnt, int sum) -> void {
		if (cnt == n - 1) {
			ans += 1;
			return;
		}
		auto it = std::lower_bound(v.begin(), v.end(), -sum);

		for (int i = it - v.begin(); i < v.size(); i++) {
			if (!vis[i]) {
				vis[i] = true;
				self(self, cnt + 1, sum + v[i]);
				vis[i] = false;
			}
		}
	};

	for (int i = 0; i < n; i++) {
		if (v[i] >= 0) {
			vis[i] = true;
			dfs(dfs, 0, v[i]);
			vis[i] = false;
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