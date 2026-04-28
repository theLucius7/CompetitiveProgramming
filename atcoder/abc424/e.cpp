#include <bits/stdc++.h>

using i64 = long long;

using u64 = unsigned long long;

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    
    Fenwick(int n_ = 0) {
        init(n_);
    }
    
    void init(int n_) {
        n = n_;
        a.assign(n, T{});
    }
    
    void add(int x, const T &v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] = a[i - 1] ^ v;
        }
    }
    
    T sum(int x) {
        T ans{};
        for (int i = x; i > 0; i -= i & -i) {
            ans = ans ^ a[i - 1];
        }
        return ans;
    }
    
    T rangeSum(int l, int r) {
        return sum(r) ^ sum(l);
    }
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, Q;
	std::cin >> N >> Q;

	std::vector<int> A(Q), B(Q);

	Fenwick<u64> fen(N + 1);

	for (int i = 0; i < Q; i++) {
		u64 h = rng();

		std::cin >> A[i] >> B[i];
		if (B[i] < A[i]) {
			std::swap(A[i], B[i]);
		}

		if (fen.rangeSum(A[i] + 1, B[i]) == 0) {
			std::cout << "Yes\n";
			fen.add(A[i], h);
			fen.add(B[i], h);
		} else {
			std::cout << "No\n";
		}
	}

	return 0;
}