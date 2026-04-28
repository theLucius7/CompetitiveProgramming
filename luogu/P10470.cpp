#include <bits/stdc++.h>

using i64 = long long;


constexpr i64 inf = 1E18;

constexpr int N = 5E6 + 10;

int trie[N][26];
int tot;
int cnt[N];

int newNode() {
    tot++;
    std::fill(trie[tot], trie[tot] + 26, 0);
    cnt[tot] = 0;
    return tot;
}

void add(std::string S) {
    int p = 1;
    for (int i = 0; i < S.size(); i++) {
        int x = S[i] - 'a';
        if (!trie[p][x]) {
            trie[p][x] = newNode();
        }
        p = trie[p][x];
    }
    cnt[p]++;
}

int query(std::string T) {
    int p = 1;
    int sum = 0;
    for (int i = 0; i < T.size(); i++) {
        int x = T[i] - 'a';
        p = trie[p][x];
        if (!p) {
            return sum;
        }
        sum += cnt[p];
    }
    return sum;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	tot = 0;
    newNode();

    int N, M;
    std::cin >> N >> M;

    for (int i = 0; i < N; i++) {
        std::string s;
        std::cin >> s;
        add(s);
    }

    for (int i = 0; i < M; i++) {
        std::string t;
        std::cin >> t;
        std::cout << query(t) << "\n";
    }

	return 0;
}