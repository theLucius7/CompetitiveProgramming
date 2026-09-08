#include <bits/stdc++.h>

using i64 = long long;

struct node {
    int l, r, sum;
    std::vector<int> num;
};

void solve() {
	int n, f;
    std::cin >> n >> f;

    std::vector<std::tuple<int, int, int>> a(n);
    for (int i = 0; i < n; i++) {
        int l, r;
        std::cin >> l >> r;
        a[i] = {l, r, i + 1};
    }

    std::sort(a.begin(), a.end(), [&](std::tuple<int, int, int> xa, std::tuple<int, int, int> ya) {
        auto [xal, xar, xua] = xa;
        auto [yal, yar, yua] = ya;

        
        if (xar != yar) {
            return xar < yar;
        }
        return xal < yal;
    });

    
    std::vector<node> ranges;
    for (int i = n - 1; i>= 0; ) {
        auto [la, ra, ua] = a[i];
        int ru = ra;

        int sum = ra - la;

        std::vector<int> nums;
        nums.push_back(ua);

        int j = i - 1;
        while (j >= 0) {
            auto [lb, rb, ub] = a[j];
            if (rb < la) {
                break;
            }

            if ()
        }
    }


    // for (int i = 0; i < n; ) {
    //     auto [la, ra, ua] = a[i];
    //     int sum = ra - la;
    //     std::vector<int> nums;
    //     nums.push_back(ua);
    //     int ru = ra;

    //     int j = i + 1;
    //     while (j < n) {
    //         auto [lb, rb, ub] = a[j];
    //         if (lb > ru) {
    //             break;
    //         }

    //         if (rb > ru) {
    //             nums.push_back(ub);

    //             sum += rb - lb;
    //             ru = rb;
    //         } else {
    //             sum += rb - lb;
    //             nums.push_back(ub);
    //         }
    //         j++;
    //     }
    //     ranges.push_back({la, ru, sum, nums});
    //     i = j;
    // }

    // for (int i = 0; i < ranges.size(); i++) {
    //     std::cout << ranges[i].l << " " << ranges[i].r << " " << ranges[i].sum << " nums:";
    //     for (int j = 0; j < ranges[i].num.size(); j++) {
    //         std::cout << ranges[i].num[j] << " \n"[j == ranges[i].num.size() - 1];
    //     }
    // }

    int cur = -1;;

    i64 ans = 0;
    if (f < ranges[0].l) {
        ans = ranges[0].l - f;
        cur = 0;
    } else {
        for (int i = 0; i < ranges.size(); i++) {
            if (i < ranges.size() - 1) {
                if (ranges[i].r <= f && ranges[i + 1].l >= f) {
                    ans = -(f - ranges[i].r);
                    cur = i + 1;
                    break;
                }
            }
            if (ranges[i].l < f && ranges[i].r) {
                if (i != 0) {
                    ans = -(ranges[i].l - ranges[i - 1].r);
                }
                cur = i;
                break;
            }
        }
    }

    for (int i = 0; i < ranges.size(); i++) {
         if (i < ranges.size() - 1) {
            ans += ranges[i + 1].l - ranges[i].r;
        }
        ans += ranges[i].sum; 
    }
    std::cout << ans << "\n";
    
    for (int i = cur; i < ranges.size(); i++) {
        for (int j = 0; j < ranges[i].num.size(); j++) {
            std::cout << ranges[i].num[j] << " ";
        }
    }

    for (int i = 0; i < cur; i++) {
        for (int j = 0; j < ranges[i].num.size(); j++) {
            std::cout << ranges[i].num[j] << " ";
        }
    }

    std::cout << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int t = 1;
	std::cin >> t;
	while (t -- ) {
		solve();
	}
	
	return 0;
}