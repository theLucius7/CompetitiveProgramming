#include <bits/stdc++.h>

using i64 = long long;

std::vector<std::string> key;

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

	int N, M;
	std::cin >> N >> M;

	std::vector<std::string> S(N);
	for (int i = 0; i < N; i++) {
		std::cin >> S[i];
	}

	key = S;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < key[i].size(); j++) {
			if (key[i][j] >= 'A' && key[i][j] <= 'Z') {
				key[i][j] = char(key[i][j] - 'A' + 'a');
			}
		}
	}

	std::vector<int> idx(N);
	std::iota(idx.begin(), idx.end(), 0);

	auto cmpIdx = [](int x, int y) {
		if (key[x] != key[y]) {
			return key[x] > key[y];
		}
		return x > y;
	};

	RMQ<int, decltype(cmpIdx)> st(idx);

	while (M--) {
		int l, r;
		std::cin >> l >> r;
		l--, r--;
		std::cout << S[st.rangeMin(l, r + 1)] << "\n";
	}

	return 0;
}