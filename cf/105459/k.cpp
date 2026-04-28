#include <bits/stdc++.h>

#define int long long

using i64 = long long;

using namespace std;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::tuple<int, int, int>> a(n);
    for (int i = 0; i < n; i++) {
        int w, l, r;
        std::cin >> w >> l >> r;
        a[i] = {w, l, r};
    }

    std::sort(a.begin(), a.end());

    int cnt = 0;
    int sum = 0;
    std::vector<int> cc(n);
    for (int i = 0; i < n; i++) {
        auto [w, l, r] = a[i];
        cnt += r;
        sum += r * w;
        cc[i] = r;
    }

    // std::vector<int> v;
    std::vector<std::pair<int, int>> nv;

    for (int i = 0; i < n; i++) {
        auto [w, l, r] = a[i];
        int d = std::min(r - l, cnt - m);
        sum -= d * w;
        cnt -= d;
        cc[i] -= d;
        // for (int j = 0; j < d; j++) {
        //     v.push_back(w);
        // }
        
        if (d != 0) {
            nv.emplace_back(w, d);
        }
        if (cnt == m) {
            break;
        }
    }

    // std::vector<int> pre(v.size() + 1);
    // for (int i = 0; i < v.size(); i++) {
        // pre[i + 1] = pre[i] + v[i];
    // }


    std::vector<int> precnt(nv.size() + 1);
    std::vector<int> presum(nv.size() + 1);
    for (int i = 0; i < nv.size(); i++) {
        precnt[i + 1] = precnt[i] + nv[i].second;
        presum[i + 1] = presum[i] + nv[i].first * nv[i].second;
    }


    // for (int i = 0; i < n; i++) {
    //     auto [w, l, r] = a[i];
    //     std::cout << w << " " << cc[i] << " \n";
    // }




    // for (int i = 0; i < v.size(); i++) {
    //     std::cout << v[i] << " \n"[i == v.size() - 1];
    // }
    // for (int i = 0; i < nv.size(); i++) {
    //     std::cout << "[" << nv[i].first << ", " << nv[i].second << "]" << " ";
    // }
    // std::cout << "\n";

    int max = sum;
    for (int i = 0; i < n; i++) {
        auto [w, l, r] = a[i];


        int lo = 0, hi = nv.size();
        while (lo < hi) {
            int m = (lo + hi) / 2;
            if (nv[m].first >= w) {
                hi = m;
            } else {
                lo = m + 1;
            }
        }
       

        int len = precnt[nv.size()] - precnt[lo];
        // int len = v.end() - std::lower_bound(v.begin(), v.end(), w);

        if (len >= cc[i]) {
            int nlo = 0, nhi = nv.size();
            while (nlo < nhi) {
                int m = (nlo + nhi + 1) / 2;
                if (precnt[nv.size()] - precnt[m] >= cc[i]) {
                    nlo = m;
                } else {
                    nhi = m - 1;
                }
            }
            max = std::max(max, sum - cc[i] * w + presum[nv.size()] - presum[nlo] - (precnt[nv.size()] - precnt[nlo] - cc[i]) * nv[nlo].first);
            // max = std::max(max, sum - cc[i] * w + pre[v.size()] - pre[v.size() - cc[i]]);
            // if (nmax != max) {
            //     std::cout << -1 << "\n";
            //     return 0;
            // }

        } else {
            max = std::max(max, sum - len * w + presum[nv.size()] - presum[lo]);
            // max = std::max(max, sum - len * w + pre[v.size()] - pre[v.size() - len]);
        }

        // std::cout << len << " ";
    }

    int nsum = 0, ncnt = 0;
    for (int i = 0; i < n; i++) {
        auto [w, l, r] = a[i];
        if (i < n - 1) {
            nsum += l * w;
            ncnt += l;
        } else {
            nsum += (m - ncnt) * w;
        }
    }
    // std::cout << nsum << "\n";

    max = std::max(max, nsum);

    std::cout << max << "\n";

    return 0;
}