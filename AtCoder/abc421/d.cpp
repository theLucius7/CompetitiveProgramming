#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 rt, ct, ra, ca, n, m, l;
    std::cin >> rt >> ct >> ra >> ca >> n >> m >> l;

    std::vector<std::pair<char, i64>> s(m), t(l);
    for (int i = 0; i < m; i++) {
        std::cin >> s[i].first >> s[i].second;
    }
    for (int i = 0; i < l; i++) {
        std::cin >> t[i].first >> t[i].second;
    }

    auto move = [](char dir) -> std::pair<i64, i64> {
        if (dir == 'U') return {-1, 0};
        if (dir == 'D') return {1, 0};
        if (dir == 'L') return {0, -1};
        if (dir == 'R') return {0, 1};
        return {0, 0};
    };

    i64 relR = rt - ra, relC = ct - ca, cnt = 0;
    int sPtr = 0, tPtr = 0;
    while (sPtr < m && tPtr < l) {
        i64 sRem = s[sPtr].second, tRem = t[tPtr].second;
        i64 cur = std::min(sRem, tRem);

        auto mvS = move(s[sPtr].first);
        auto mvT = move(t[tPtr].first);
        i64 dr = mvS.first - mvT.first, dc = mvS.second - mvT.second;
        if (dr == 0 && dc == 0) {
            if (relR == 0 && relC == 0) cnt += cur;
        } else if (dr == 0) {
            if (relR == 0 && dc != 0 && -relC % dc == 0) {
                i64 i = -relC / dc;
                if (i > 0 && i <= cur) cnt++;
            }
        } else if (dc == 0) {
            if (relC == 0 && dr != 0 && -relR % dr == 0) {
                i64 i = -relR / dr;
                if (i > 0 && i <= cur) cnt++;
            }
        } else {
            if (-relR % dr == 0 && -relC % dc == 0) {
                i64 iR = -relR / dr, iC = -relC / dc;
                if (iR == iC && iR > 0 && iR <= cur) cnt++;
            }
        }

        relR += cur * dr;
        relC += cur * dc;
        s[sPtr].second -= cur;
        t[tPtr].second -= cur;
        if (s[sPtr].second == 0) sPtr++;
        if (t[tPtr].second == 0) tPtr++;
    }

    std::cout << cnt << std::endl;
    return 0;
}
