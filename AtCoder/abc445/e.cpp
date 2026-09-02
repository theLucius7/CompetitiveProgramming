#include <bits/stdc++.h>

using i64 = long long;

i64 mul(i64 a, i64 b, i64 p) {
    i64 c = a * b - i64(1.0L * a * b / p) * p;
    c %= p;
    if (c < 0) {
        c += p;
    }
    return c;
}

i64 power(i64 a, i64 b, i64 p) {
    i64 res = 1;
    for (; b; b /= 2, a = mul(a, a, p)) {
        if (b % 2) {
            res = mul(res, a, p);
        }
    }
    return res;
}

constexpr i64 P = 998244353;

std::vector<int> minp, primes;

void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        
        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
}

bool isprime(int n) {
    return minp[n] == n;
}

constexpr int MAXN = 1E7;

int max[MAXN], nmax[MAXN];
int cnt[MAXN];

void solve() {
	int N;
	std::cin >> N;

	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}

	std::vector<int> used;

	for (int i = 0; i < N; i++) {
		int val = A[i];
		while (val > 1) {
			int u = 0, p = minp[val];
			while (minp[val] == p) {
				u++;
				val /= p;
			}

			if (u && !max[p]) {
				used.push_back(p);
			}

			if (u > max[p]) {
				nmax[p] = max[p];
				max[p] = u;
				cnt[p] = 1;
			} else if (u == max[p]) {
				cnt[p]++;
			} else if (u > nmax[p]) {
				nmax[p] = u;
			}
		}
	}

	// return;

	i64 lcm = 1;
	for (int p : used) {
		lcm = mul(lcm, power(p, max[p], P), P);
	}
	
	for (int i = 0; i < N; i++) {
		
		i64 ans = lcm;
		int val = A[i];
		while (val > 1) {
			int u = 0, p = minp[val];
			while (minp[val] == p) {
				u++;
				val /= p;
			}

			if (u == max[p] && cnt[p] == 1) {
				ans = mul(ans, power(power(p, max[p] - nmax[p], P), P - 2, P), P);
			} 
		}	

		std::cout << ans << " \n"[i == N - 1];
	}

	for (int p : used) {
		max[p] = 0, nmax[p] = 0, cnt[p] = 0;
	}

}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	sieve(1E7 + 10);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}