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

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::vector<int> A(N);
	std::vector<int> diff(3E5 + 10);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
		diff[0] += 1;
		diff[A[i]] -= 1;
	}

	for (int i = 1; i < 3E5 + 1; i++) {
		diff[i] += diff[i - 1];
	}

	for (int i = 0; i < 3E5 + 1; i++) {
		diff[i + 1] += diff[i] / 10;
		diff[i] %= 10;
	}

	int S = -1;
	for (int i = 3E5; i >= 0; i--) {
		if (diff[i] != 0) {
			S = i;
			break;
		}
	}

	if (S == -1) {
		std::cout << 0 << "\n";
	} else {
		for (int i = S; i >= 0; i--) {
			std::cout << diff[i];
		}
		std::cout << "\n";
	}


	return 0;
}