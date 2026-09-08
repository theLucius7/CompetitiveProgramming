#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    // 1s 2h 2a 1n 1g 1i
    std::string t1 = "SHANGI", t2 = "shangi";
    std::vector<int> cnt(6);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            if (s[i] == t1[j] || s[i] == t2[j]) {
                cnt[j]++;
                // std::cout << i << " " << j << "\n";
                break;
                // std::cout << s[i] << " ";
            }
        }
    }
    cnt[1] /= 2, cnt[2] /= 2;

    // std::cout << "\n";
    // for (int i = 0; i < 6; i++) {
    //     std::cout << cnt[i] << " \n"[i == 5];
    // }

    std::cout << *min_element(cnt.begin(), cnt.end()) << "\n";

    return 0;
}