#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

std::map<std::string, int> mp;

void solve() {
    std::string a, b;
    for (int i = 0; i < 3; i++) {
        std::string s;
        std::cin >> s;
        a += s;
    }

    int cnt = 1;
    std::vector<int> tod(10);
    for (int i = 0; i < 3; i++) {
        std::string s;
        std::cin >> s;
        b += s;
    }

    for (int i = 0; i < 9; i++) {
        tod[a[i] - '0'] = cnt;
        cnt++;
    }

    for (int i = 0; i < 9; i++) {
        b[i] = tod[b[i] - '0'] + '0';
    }

    // std::cout << a << "\n";
    std::cout << (mp.count(b) ? mp[b] : -1) << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string v = "123456789";
    mp[v] = 0;

    std::queue<std::pair<std::string, int>> q;
    q.push({v, 0});
    while (q.size()) {
        auto [u, cnt] = q.front();
        q.pop();

        for (int i = 0; i < 3; i++) {
            std::string s = u;
            std::swap(s[6 + i], s[3 + i]);
            std::swap(s[3 + i], s[i]);

            if (!mp.count(s)) {
                q.push({s, cnt + 1});
                mp[s] = cnt + 1;
            }
        }

        for (int i = 0; i < 3; i++) {
            std::string s = u;
            std::swap(s[i * 3 + 1], s[i * 3 + 2]);
            std::swap(s[i * 3 + 1], s[i * 3]);

            if (!mp.count(s)) {
                q.push({s, cnt + 1});
                mp[s] = cnt + 1;
            }
        }


        std::string s = u;
        std::swap(s[0], s[2]);
        std::swap(s[0], s[6]);
        std::swap(s[6], s[8]);
        std::swap(s[1], s[5]);
        std::swap(s[1], s[3]);
        std::swap(s[3], s[7]);

        if (!mp.count(s)) {
            q.push({s, cnt + 1});
            mp[s] = cnt + 1;
        }
    }

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }


    return 0;
}