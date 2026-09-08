#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }

    std::vector<int> v;
    for (int i = 0; i < n; i++) {
        v.push_back(i);
    }
    std::string ans;
    int cur = 0;
    int nk = k;
    while (true) {
        std::vector uu(26, std::vector<int>());
        for (int i = 0; i < v.size(); i++) {
            if (cur < s[v[i]].size()) {
                uu[s[v[i]][cur] - 'a'].push_back(v[i]);
            } else {
                nk--;
            }
        }
        v.clear();

        // for (int i = 0; i < 26; i++) {
        //     std::cout << (char)(i + 'a') << ": ";
        //     for (int j = 0; j < uu[i].size(); j++) {
        //         std::cout << uu[i][j] << " ";
        //     }
        //     std::cout << "\n";
        // }

        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            cnt += !uu[i].empty();
        }

        if (cnt >= nk) {
            break;
        }

        int pre = 0;
        for (int i = 0; i < 26; i++) {
            if (uu[i].empty()) {
                continue;
            }
            if (nk <= pre + cnt + uu[i].size() - 1) {
                for (int j = 0; j < uu[i].size(); j++) {
                    v.push_back(uu[i][j]);
                }
                cur++;
                ans.push_back((char)(i + 'a'));
                nk = nk - pre - cnt + 1;
                break;
            }
            pre += uu[i].size() - 1;
        }



        

        // break;
    }

    std::cout << (ans.empty() ? "EMPTY" : ans) << "\n";

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T -- ) {
        solve();
    }

    return 0;
}