#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 inf = 4E18 + 1;

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

	int N;
	std::cin >> N;

	std::vector<std::pair<i64, i64>> p(N);
	for (int i = 0; i < N; i++) {
		std::cin >> p[i].first >> p[i].second;
	}

	std::sort(p.begin(), p.end());

	std::vector<i64> X(N), Y(N);
	for (int i = 0; i < N; i++) {
		X[i] = p[i].first;
		Y[i] = p[i].second;
	}



	RMQ<i64, std::greater<i64>> stMaxX(X);
	RMQ<i64, std::less<i64>> stMinX(X);
	RMQ<i64, std::greater<i64>> stMaxY(Y);
	RMQ<i64, std::less<i64>> stMinY(Y);


	auto calc = [&](int l, int r) {
		return(stMaxX.rangeMin(l, r) - stMinX.rangeMin(l, r)) * (stMaxY.rangeMin(l, r) - stMinY.rangeMin(l, r));
	};

	i64 cur = calc(0, N);

	i64 min = inf;
	for (int i = 1; i < N - 1; i++) {
		min = std::min(min, calc(0, i + 1) + calc(i + 1, N));
	}

	std::sort(p.begin(), p.end(), [](std::pair<i64, i64> a, std::pair<i64, i64> b) {
		return a.second < b.second;
	});

	for (int i = 0; i < N; i++) {
		X[i] = p[i].first;
		Y[i] = p[i].second;
	}

	RMQ<i64, std::greater<i64>> stMaxX2(X);
	RMQ<i64, std::less<i64>> stMinX2(X);
	RMQ<i64, std::greater<i64>> stMaxY2(Y);
	RMQ<i64, std::less<i64>> stMinY2(Y);

	auto calc2 = [&](int l, int r) {
		return(stMaxX2.rangeMin(l, r) - stMinX2.rangeMin(l, r)) * (stMaxY2.rangeMin(l, r) - stMinY2.rangeMin(l, r));
	};

	for (int i = 1; i < N - 1; i++) {
		min = std::min(min, calc2(0, i + 1) + calc2(i + 1, N));
	}

	std::cout << cur - min << "\n";


	return 0;
}