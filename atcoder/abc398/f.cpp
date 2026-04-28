#include <bits/stdc++.h>

using i64 = long long;

namespace ranges = std::ranges;
namespace views = std::views;

std::vector<int> manacher(std::string s) {
    std::string t = "#";
    for (auto c : s) {
        t += c;
        t += '#';
    }
    int n = t.size();
    std::vector<int> r(n);
    for (int i = 0, j = 0; i < n; i++) {
        if (2 * j - i >= 0 && j + r[j] > i) {
            r[i] = std::min(r[2 * j - i], j + r[j] - i);
        }
        while (i - r[i] >= 0 && i + r[i] < n && t[i - r[i]] == t[i + r[i]]) {
            r[i] += 1;
        }
        if (i + r[i] > j + r[j]) {
            j = i;
        }
    }
    return r;
}

// i -> 2 * i + 1

// #0#1#2#3

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string S;
	std::cin >> S;


	auto r = manacher(S);

   // 2 * l + 1, l + n, 2 * (n - 1) + 1 = 2 * n - 1

	// l + n + r[l + n] - 1 >= 2 * n - 1

	int n = S.size();
	int l = 0;
	while (l + n + r[l + n] - 1 < 2 * n - 1) {
		l++;
	}

	auto ans = S;
	ranges::copy(S.substr(0, l) | views::reverse, std::back_inserter(ans));

	std::cout << ans << "\n";

	return 0;
}	