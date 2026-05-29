#include <bits/stdc++.h>

#define int unsigned long long

using i64 = long long;

using i128 = __int128;
 
std::ostream &operator<<(std::ostream &os, i128 n) {
    if (n == 0) {
        return os << 0;
    }
    std::string s;
    while (n > 0) {
        s += char('0' + n % 10);
        n /= 10;
    }
    std::reverse(s.begin(), s.end());
    return os << s;
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, A, B;
	std::cin >> N >> A >> B;

	std::string S;
	std::cin >> S;

	std::vector<i128> pre(N + 1, 0);
    for (int i = 0; i < N; i++) {
        pre[i + 1] = pre[i] + (S[i] == 'a');
    }

	std::vector<i128> cnt(2, 0);
	int r = -1;
	i128 q = 0;
	i128 ans = 0;
	for (int l = 0; l < N; l++) {
		while (r + 1 < N && cnt[1] + (S[r + 1] == 'b') < B) {
            r++;
            cnt[S[r] - 'a']++;
        }

        q = std::max(q, (i128)l + 1);
        while (q <= N && pre[q] < pre[l] + A) {
            q++;
        }

        if (q <= N) {
            i128 rA = q - 1;
            if (rA <= r) {
                ans = ans + (i128)(r - rA + 1);
            }
        }

        if (l <= r) {
            cnt[S[l] - 'a']--;
        }
	}


	std::cout << ans << "\n";

	return 0;
}