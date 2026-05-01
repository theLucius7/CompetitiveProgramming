#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;

    std::reverse(s.begin(), s.end());

    int max = -1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '5') {
            max = std::max(max, i);
            int j = i + 1;
            while (j < s.size() && s[j] == '9') {
                s[j] = '0';
                j++;
            }

            if (j < s.size()) {
                s[j] = (char)(s[j] + 1);
            } else {
                s.push_back('1');
            }
        }
    }

    // std::cout << max << " ";

    for (int i = s.size() - 1; i >= 0; i--) {
        if (i > max) {
            std::cout << s[i];
        } else {
            std::cout << '0';
        }
    }


    std::cout << "\n";
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