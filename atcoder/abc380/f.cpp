#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, M, L;
    std::cin >> N >> M >> L;

    std::vector<int> A(N), B(M), C(L);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    for (int i = 0; i < M; i++) {
        std::cin >> B[i];
    }
    for (int i = 0; i < L; i++) {
        std::cin >> C[i];
    }

    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());
    std::sort(C.begin(), C.end());

    std::map<std::array<std::vector<int>, 3>, bool> w;
    auto win = [&](this auto &&self, auto &&a, auto &&b, auto &&c) {
        if (w.contains({a, b, c})) {
            return w[{a, b, c}];
        }

        bool &res = w[{a, b, c}];

        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < c.size() && a[i] > c[j]; j++) {
                auto na = a;
                na.erase(na.begin() + i);
                na.insert(std::lower_bound(na.begin(), na.end(), c[j]), c[j]);
                auto nc = c;
                nc.erase(nc.begin() + j);
                nc.insert(std::lower_bound(nc.begin(), nc.end(), a[i]), a[i]);

                if (!self(b, na, nc)) {
                    return res = true;
                }
            }
            auto na = a;
            na.erase(na.begin() + i);
            auto nc = c;
            nc.insert(std::lower_bound(nc.begin(), nc.end(), a[i]), a[i]);
            if (!self(b, na, nc)) {
                return res = true;
            }
        }
        return res = false;
    };

    std::cout << (win(A, B, C) ? "Takahashi" : "Aoki") << "\n";

	return 0;
}
