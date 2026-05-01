#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::unordered_map<char, int> cnt;
    for (int i = 0; i < n; i++) {
        cnt[s[i]]++;
    }
    cnt['N'] /= 2, cnt['E'] /= 2, cnt['S'] /= 2, cnt['W'] /= 2;

    std::cout << ((cnt['N'] + cnt['E'] + cnt['S'] + cnt['W']) % 4 == 0 ? "YES" : "NO") << "\n";
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