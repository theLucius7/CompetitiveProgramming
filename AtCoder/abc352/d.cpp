#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E8 + 1;

template<class T, class Cmp = std::less<T>>
struct RMQ {
    const int n;
    const Cmp cmp;
    std::vector<std::vector<T>> a;
    RMQ(const std::vector<T> &init) : n(init.size()), cmp(Cmp()) {
        int lg = std::__lg(n);
        a.assign(n, std::vector<T>(lg + 1));
        for (int j = 0; j <= lg; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                a[i][j] = (j == 0 ? init[i] : std::min(a[i][j - 1], a[i + (1 << (j - 1))][j - 1], cmp));
            }
        }
    }
    T rangeMin(int l, int r) {
        int k = std::__lg(r - l);
        return std::min(a[l][k], a[r - (1 << k)][k], cmp);
    }
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, K;
	std::cin >> N >> K;

	std::vector<int> P(N);
	for (int i = 0; i < N; i++) {
		std::cin >> P[i];
		P[i]--;
	}

	std::vector<int> idx(N);
	for (int i = 0; i < N; i++) {
		idx[P[i]] = i;
	}

	RMQ<int, std::greater<int>> stMax(idx);
	RMQ<int, std::less<int>> stMin(idx);

	int min = inf;
	for (int i = 0; i + K - 1 < N; i++) {
		min = std::min(min, stMax.rangeMin(i, i + K) - stMin.rangeMin(i, i + K));
	}
	std::cout << min << "\n";

	return 0;
}