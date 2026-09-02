#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

std::map<char, int> ff, fs;
std::vector<std::vector<bool>> vis(15, std::vector<bool>(4));

int cmp(std::pair<int, std::array<int, 5>> a, std::pair<int, std::array<int, 5>> b) {
    if (a.first > b.first) {
        return 1;
    } else if (a.first < b.first) {
        return -1;
    } else {
        auto ay = a.second;
        auto by = b.second;
        for (int i = 0; i < 5; i++) {
            if (ay[i] > by[i]) {
                return 1;
            } else if (ay[i] < by[i]) {
                return -1;
            }
        }   
    }
    return 0;
}

bool isRoyalflush(std::vector<std::pair<int, int>> a) {
    std::sort(a.begin(), a.end());
    for (int i = 0; i < 5; i++) {
        if (a[i].first != 10 + i) {
            return false;
        }
    }
    for (int i = 1; i < 5; i++) {
        if (a[i].second != a[i - 1].second) {
            return false;
        }
    }
    return true;
}

bool isStraightflush(std::vector<std::pair<int, int>> a) {
    for (int i = 0; i < 5; i++) {
        if (a[i].first == 14) {
            a[i].first = 1;
        }
    }

    std::sort(a.begin(), a.end());
    for (int i = 1; i < 5; i++) {
        if (a[i].first != a[i - 1].first + 1) {
            return false;
        }
        if (a[i].second != a[i - 1].second) {
            return false;
        }
    }
    return true;
}

bool isFourofakind(std::vector<std::pair<int, int>> a) {
    std::sort(a.begin(), a.end());
    if (a[0].first == a[3].first || a[1].first == a[4].first) {
        return true;
    } else {
        return false;
    }
}

bool isFullhouse(std::vector<std::pair<int, int>> a) {
    std::sort(a.begin(), a.end());
    if (a[0].first == a[2].first && a[3].first == a[4].first) {
        return true;
    }    
    if (a[0].first == a[1].first && a[2].first == a[4].first) {
        return true;
    }
    return false;
}

bool isFlush(std::vector<std::pair<int, int>> a) {
    std::sort(a.begin(), a.end(), std::greater<>());
    for (int i = 1; i < 5; i++) {
        if (a[i].first >= a[i - 1].first) {
            return false;
        }
    }
    for (int i = 1; i < 5; i++) {
        if (a[i].second != a[i - 1].second) {
            return false;
        }
    }

    return true;
}

bool isStraight(std::vector<std::pair<int, int>> &a) {
    sort(a.begin(), a.end());
    int f = 1;
    for (int i = 1; i < 5; i ++ ) {
        if (a[i].first != a[i - 1].first + 1) {
            f = 0;
            break;
        }
    }
    if (f) {
        return true;
    }
    if (a[4].first == 14) {
        a[4].first = 1;
    }
    sort(a.begin(), a.end());
    for (int i = 1; i < 5; i ++ ) {
        if (a[i].first != a[i - 1].first + 1) {

            for (int j = 0; j < 5; j++) {
                if (a[j].first == 1) {
                    a[j].first = 14;
                }
            }
            return false;
        }
    }
    return true;
}

bool isThreeofakind(std::vector<std::pair<int, int>> &a) {
    std::vector<std::pair<int, int>> b(5);

    sort(a.begin(), a.end());
    for (int i = 2; i < 5; i ++ ) {
        if (a[i].first == a[i - 2].first) {
            b[0] = a[i];
            b[1] = a[i];
            b[2] = a[i];

            for (int j = 4; j >= 0; j--) {
                if (a[j].first != b[0].first) {
                    b[3] = a[j];                   
                    break;
                }
            } 
            for (int j = 4; j >= 0; j--) {
                if (a[j].first != b[0].first && a[j].first != b[3].first) {
                    b[4] = a[j];
                    break;
                }
            }
            a = b;
            return true;
        }
    }
    return false;
}

bool isTwopairs(std::vector<std::pair<int, int>> &a) {
    std::vector<std::pair<int, int>> b(5);

    sort(a.begin(), a.end(), std::greater<>());
    for (int i = 1; i < 5; i ++ ) {
        if (a[i].first == a[i - 1].first) {
            b[0] = a[i];
            b[1] = a[i];
            for (int j = i + 2; j < 5; j ++ ) {
                if (a[j].first == a[j - 1].first) {
                    b[2] = a[j];
                    b[3] = a[j];

                    for (int k = 0; k < 5; k++) {
                        if (a[k].first != b[0].first && a[k].first != b[2].first) {
                            b[4] = a[k];
                            break;
                        }
                    }

                    a = b;
                    return true;
                }
            }
        }
    }
    return false;
}

bool isPair(std::vector<std::pair<int, int>> &a) {
    sort(a.begin(), a.end(), std::greater<>());

    std::vector<std::pair<int, int>> b(5);
    for (int i = 1; i < 4; i ++ ) {
        if (a[i].first == a[i - 1].first) {
            b[0] = a[i];
            b[1] = a[i];

            for (int u = 0; u < 5; u++) {
                if (a[u].first != b[0].first) {
                    b[2] = a[u];
                    break;
                }
            }

            for (int u = 0; u < 5; u++) {
                if (a[u].first != b[0].first && a[u].first != b[2].first) {
                    b[3] = a[u];
                    break;
                }
            }

            for (int u = 0; u < 5; u++) {
                if (a[u].first != b[0].first && a[u].first != b[2].first && a[u].first != b[3].first) {
                    b[4] = a[u];
                    break;
                }
            }

            a = b;

            return true;
        }
    }
    return false;
}


void solve() {
    std::vector<std::pair<int, int>> c(4), p(4);
    for (int i = 1; i <= 14; i++) {
        for (int j = 0; j < 4; j++) {
            vis[i][j] = false;
        }
    }

    for (int i = 0; i < 4; i++) {
        std::string s;
        std::cin >> s;
        c[i].first = ff[s[0]];
        c[i].second = fs[s[1]];
        vis[c[i].first][c[i].second] = true;
    }
    for (int i = 0; i < 4; i++) {
        std::string s;
        std::cin >> s;
        p[i].first = ff[s[0]];
        p[i].second = fs[s[1]];
        vis[p[i].first][p[i].second] = true;
    }

    auto calc = [&](int i, int j, int k) -> std::pair<int, std::array<int, 5>>{
        std::pair<int, std::array<int, 5>> curp = {-1, {-1, -1, -1, -1, -1}};
        std::vector<std::pair<int, int>> a;
        if (k == 0) {
            a = c;
        } else {
            a = p;
        }
        
        a.push_back({i, j});

        if (isRoyalflush(a)) {
            curp = {10, {10, 11, 12, 13, 14}};
        } else if (isStraightflush(a)) {
            for (int i = 0; i < 5; i++) {
                if (a[i].first == 14) {
                    a[i].first = 1;
                }
            }
            std::sort(a.begin(), a.end());
            curp.first = 9;
            for (int i = 0; i < 5; i++) {
                curp.second[i] = a[i].first;
            }
        } else if (isFourofakind(a)) {
            curp.first = 8;
            std::sort(a.begin(), a.end());
            if (a[0].first == a[3].first) {
                curp.second = {a[0].first, a[0].first, a[0].first, a[0].first, a[4].first};
            } else {
                curp.second = {a[1].first, a[1].first, a[1].first, a[1].first, a[0].first};
            }
        } else if (isFullhouse(a)) {
            curp.first = 7;
            std::sort(a.begin(), a.end());
            if (a[0].first == a[2].first) {
                curp.second = {a[0].first, a[0].first, a[0].first, a[3].first, a[3].first};
            } else {
                curp.second = {a[2].first, a[2].first, a[2].first, a[0].first, a[0].first};
            }
        } else if (isFlush(a)) {
            std::sort(a.begin(), a.end(), std::greater<>());
            curp.first = 6;
            for (int i = 0; i < 5; i++) {
                curp.second[i] = a[i].first;
            }
        } else if (isStraight(a)) {
            std::sort(a.begin(), a.end(), std::greater<>());
            curp.first = 5;
            for (int i = 0; i < 5; i++) {
                curp.second[i] = a[i].first;
            }
        } else if (isThreeofakind(a)) {
            curp.first = 4;
            for (int i = 0; i < 5; i++) {
                curp.second[i] = a[i].first;
            }
        } else if (isTwopairs(a)) {
            curp.first = 3;
            for (int i = 0; i < 5; i++) {
                curp.second[i] = a[i].first;
            }
        } else if (isPair(a)) {
            curp.first = 2;
            for (int i = 0; i < 5; i++) {
                curp.second[i] = a[i].first;
            }
        } else {
            std::sort(a.begin(), a.end(), std::greater<>());
            curp.first = 1;
            for (int i = 0; i < 5; i++) {
                curp.second[i] = a[i].first;
            }
        }
        return curp;
    };

    bool dalaohu = true;
    for (int px = 2; px <= 14; px++) {
        for (int py = 0; py < 4; py++) {
            std::map<int, int> cnt;
            bool passed = false;
            for (int pc = 2; pc <= 14; pc++) {
                for (int pd = 0; pd < 4; pd++) {
                    if (std::make_pair(px, py) != std::make_pair(pc, pd) && !vis[px][py] && !vis[pc][pd]) {
                        int res = cmp(calc(px, py, 1), calc(pc, pd, 0));
                        cnt[res]++;
                        if (res == -1) {
                            passed = true;
                        }
                    }
                }
            }
            
            if (!passed && !vis[px][py]) {
                dalaohu = false;
            }

            if (cnt[1] > 0 && cnt[-1] == 0 && cnt[0] == 0) {
                std::cout << "GeiWoCaPiXie\n";
                return;
            }
        }
    }

    if (!dalaohu) {
        std::cout << "PaiMeiYouWenTi\n";
    } else {
        std::cout << "WoYaoYanPai\n";
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for (int i = 2; i <= 9; i++) {
        ff['0' + i] = i;
    }
    ff['T'] = 10, ff['J'] = 11, ff['Q'] = 12, ff['K'] = 13, ff['A'] = 14;
    fs['C'] = 0, fs['D'] = 1, fs['H'] = 2, fs['S'] = 3;

    int t = 1;
    std::cin >> t; 
    while (t--) {
        solve();
    }

    return 0;
}
