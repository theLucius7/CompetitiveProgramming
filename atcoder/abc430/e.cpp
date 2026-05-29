#include <bits/stdc++.h>

using i64 = long long;

std::vector<int> kmp(std::string s) {
    int n = s.size();
    std::vector<int> f(n + 1);
    for (int i = 1, j = 0; i < n; i++) {
        while (j && s[i] != s[j]) {
            j = f[j];
        }
        j += (s[i] == s[j]);
        f[i + 1] = j;
    }
    return f;
}

void solve() {
    std::string A, B;
    std::cin >> A >> B;

    std::string S = A + A;
    auto f = kmp(B);
    int j = 0, ans = -1;
    for (int i = 0; i < S.size(); i++) {
        while (j && S[i] != B[j]) {
            j = f[j];
        }
        if (S[i] == B[j]) {
            j++;
        }
        if (j == B.size()) {
            int x = i - B.size() + 1;
            if (x < A.size()) {
                ans = x;
                break;
            }
            j = f[j];
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
