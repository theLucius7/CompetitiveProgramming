#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using ll = long long;

constexpr int P = 998244353;

ll qmi(ll a, ll b, ll mod)
{
    ll ans = 1 % mod;
    while(b)
    {
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

int C(int a, int b, int p)
{
    if (b > a) return 0;
    int res = 1;
    for (int i = 1, j = a; i <= b; i ++, j -- )
    {
        res = (ll)res * j % p;
        res = (ll)res * qmi(i, p - 2, p) % p;
    }
    return res;
}
int lucas(ll a, ll b, int p)
{
    if (a < p && b < p) return C(a, b, p);
    return (ll)C(a % p, b % p, p) * lucas(a / p, b / p, p) % p;
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string s;
	std::cin >> s;

	std::vector<std::pair<int, int>> v;
	for (int l = 0; l < s.size(); ) {
		int r = l + 1;
		while (r < s.size() && s[l] == s[r]) {
			r++;
		}
		v.emplace_back(s[l] - '0', r - l);
		l = r;
	}

	std::vector<std::vector<int>> precnt(10, std::vector<int>(v.size()));
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j <= 9; j++) {
			if (i == 0) {
				break;
			}
			precnt[j][i] = precnt[j][i - 1];
		}
		precnt[v[i].first][i] += v[i].second;
	}

	std::vector<std::vector<int>> sufcnt(10, std::vector<int>(v.size()));
	for (int i = v.size() - 1; i >= 0; i--) {
		for (int j = 0; j <= 9; j++) {
			if (i == v.size() - 1) {
				break;
			}
			sufcnt[j][i] = sufcnt[j][i + 1];
		}
		sufcnt[v[i].first][i] += v[i].second;
	}

	// std::cout << cnt[v[0].first] << "?";
	i64 res = 0;
	for (int i = 1; i < v.size(); i++) {
		if (v[i].first == 0) {

		} else {
			// std::cout << v[i].first - 1 << " ";
			// std::cout << v[i].second << " " << cnt[v[i].first - 1] << "\n";
			res += lucas(sufcnt[v[i].first][i] + precnt[v[i].first - 1][i - 1], sufcnt[v[i].first][i], P) - 1;
		}
		res %= P;
		// cnt[v[i].first] += v[i].second;
	}

	std::cout << (res + P) % P << "\n";

	return 0;
}