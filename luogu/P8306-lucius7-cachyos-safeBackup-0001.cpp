#include <bits/stdc++.h>

using i64 = long long;


constexpr i64 inf = 1E18;

constexpr int N = 5E6 + 10;

int trie[N][62];
int tot;
int cnt[N];

int newNode() {
    tot++;
    std::fill(trie[tot], trie[tot] + 62, 0);
    cnt[tot] = 0;
    return tot;
}

int getx(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a';
    } else if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 26;
    } else {
        return c - '0' + 52;
    }
}

void add(std::string S) {
    int p = 1;
    for (int i = 0; i < S.size(); i++) {
        int x = getx(S[i]);
        if (!trie[p][x]) {
            trie[p][x] = newNode();
        }
        p = trie[p][x];
        cnt[p]++;
    }
}

int query(std::string T) {
    int p = 1;
    for (int i = 0; i < T.size(); i++) {
        int x = getx(T[i]);
        p = trie[p][x];
        if (!p) {
            return 0;
        }
    }
    return cnt[p];
}

void solve() {
    tot = 0;
    newNode();
    
    int n, m;
    std::cin >> n >> m;

    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        add(s);
    }

    for (int i = 0; i < m; i++) {
        std::string t;
        std::cin >> t;
        std::cout << query(t) << "\n";
    }
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