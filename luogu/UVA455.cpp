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

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::string s;
	std::cin >> s;

	auto v = kmp(s);
	std::cout << (s.size() % (s.size() - v[s.size()]) == 0 ? s.size() - v[s.size()] : s.size()) << "\n";


	return 0;
}