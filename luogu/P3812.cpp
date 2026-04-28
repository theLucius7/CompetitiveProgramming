#include <bits/stdc++.h>

using i64 = long long;

struct Basis {
    int a[20] {};
    int t[20] {};
    
    Basis() {
        std::fill(t, t + 20, -1);
    }
    
    void add(int x, int y = 1E9) {
        for (int i = 0; i < 20; i++) {
            if (x >> i & 1) {
                if (y > t[i]) {
                    std::swap(a[i], x);
                    std::swap(t[i], y);
                }
                x ^= a[i];
            }
        }
    }
    
    bool query(int x, int y = 0) {
        for (int i = 0; i < 20; i++) {
            if ((x >> i & 1) && t[i] >= y) {
                x ^= a[i];
            }
        }
        return x == 0;
    }
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	Basis basis;
	for (int i = 0; i < n; i++) {
		int a;
		std::cin >> a;
		basis.add(a, i);
	}

	int max = 0;
	for (int i = 19; i >= 0; i--) {
		if (basis.t[i] >= 0) {
			max = std::max(max, max ^ basis.a[i]);
		}
	}

	std::cout << max << "\n";

	return 0;
}