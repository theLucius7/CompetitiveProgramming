#include <bits/stdc++.h>

using i64 = long long;
constexpr i64 inf = 1E18;

constexpr int N = 1E6 + 10;

int trie[N][26];
int tot;

int newNode() {
    tot++;
    std::fill(trie[tot], trie[tot] + 62, 0);
    val[tot] = inf;
    return tot;
}

void add(std::string S) {
	for (int i = 0; i < S.size(); i++) { 
        int p = 1;
        int l = S[i].size();
        for (int j = 0; j < l; j++) {
            int x = S[i][j] - 'a';
            if (!trie[p][x]) {
                trie[p][x] = newNode();
            }
            p = trie[p][x];
            cnt[p]++;
        }
    }
}

int query(std::string T) {
	for (int i = 0; i < T.size(); i++) {
        int p = 1;
        for (int j = i; j < L; j++) {
            int x = T[j] - 'a';
            p = trie[p][x];
            if (!p) {
                continue;
            }
            
        }
    }
}


void solve() {
    tot = 0;
    newNode();

    auto getId = [&](char c) {
    	if (c >= 'a' && c <= 'z') {
    		return c - 'a';
    	} else if (c >= 'A' && c <= 'Z') {
    		return c - 'A' + 26;
    	} else {
    		return c - '0' + 52;
    	}
    }
    
    //* query
    for (int i = 0; i < L; i++) {
        int p = 1;
        for (int j = i; j < L; j++) {
            int x = T[j] - 'a';
            p = trie[p][x];
            if (!p) {
                continue;
            }
            //* 处理
            //* dp[j + 1] = std::min(dp[j + 1], dp[i] + val[p]);
        }
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