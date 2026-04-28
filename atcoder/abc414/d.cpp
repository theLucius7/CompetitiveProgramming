#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// 判断字符串是否回文
bool is_palindrome(const string& s) {
    int n = (int)s.size();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i]) return false;
    }
    return true;
}

// 将数字转换成 base 进制字符串
string to_base(i64 x, int base) {
    if (x == 0) return "0";
    string res;
    while (x > 0) {
        res += '0' + (x % base);
        x /= base;
    }
    reverse(res.begin(), res.end());
    return res;
}

// 构造回文数（奇数长度或偶数长度）
i64 make_palindrome(i64 half, bool odd_length) {
    string s = to_string(half);
    string t = s;
    if (odd_length) {
        t.pop_back();
    }
    reverse(t.begin(), t.end());
    s += t;
    return stoll(s);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A; i64 N;
    cin >> A >> N;

    i64 ans = 0;

    // 枚举回文数长度
    for (int length = 1; length <= 12; length++) {
        int half_len = (length + 1) / 2;

        i64 start = (i64)pow(10, half_len - 1);
        i64 end = (i64)pow(10, half_len);

        // 特殊处理长度为1的情况，start从1开始即可
        if (half_len == 1) start = 1;

        for (i64 half = start; half < end; half++) {
            i64 pal;
            if (length % 2 == 1) {
                pal = make_palindrome(half, true);
            } else {
                pal = make_palindrome(half, false);
            }

            if (pal > N) break;

            string baseA = to_base(pal, A);
            if (is_palindrome(baseA)) {
                ans += pal;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
