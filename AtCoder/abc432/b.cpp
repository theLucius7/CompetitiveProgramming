#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string s;
    std::cin >> s;

    std::sort(s.begin(), s.end());

    int x = s.size() - 1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '0') {
            x = i;
            break;
        }
    }

    std::cout << s[x];
    for (int i = 0; i < s.size(); i++) {
        if (i == x) {
            continue;
        }
        std::cout << s[i];
    }

	return 0;
}