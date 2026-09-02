#include <bits/stdc++.h>

#define int long long

using i64 = long long;

std::map<std::string, int> map;
std::map<int, std::string> rmap;

void solve() {
    int y, m, d;
    std::cin >> y >> m >> d;

    i64 x = 360 * y + 30 * m + d;

    std::string s;
    std::cin >> s;

    int ny, nm, nd;
    std::cin >> ny >> nm >> nd;

    i64 nx = 360 * ny + 30 * nm + nd;

    std::cout << rmap[(map[s] + (nx - x) % 5 + 5) % 5] << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    map["Monday"] = 0;
    map["Tuesday"] = 1;
    map["Wednesday"] = 2;
    map["Thursday"] = 3;
    map["Friday"] = 4;
    rmap[0] = "Monday";
    rmap[1] = "Tuesday";
    rmap[2] = "Wednesday";
    rmap[3] = "Thursday";
    rmap[4] = "Friday";


    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }


    return 0;
}