#include <bits/stdc++.h>

using i64 = long long;

using namespace std;

#define int long long

std::vector<int> mp{1, 0, 0, 0, 1, 0, 1, 0, 2, 1};

void solve() {
	std::string s;
	int k;
	std::cin >> s >> k;

	int sum = stoll(s);
	int cnt = 0;
	for (int i = 0; i < min((int)100,k); i++) {
		sum = 0;
		for (int j = 0; j < s.size(); j++) {
			sum += mp[s[j] - '0'];
		}
		cnt++;
		s = std::to_string(sum);

	}
	if(cnt == k){
		cout << sum << "\n";
	}else{
		if((k- cnt) % 2){
			cout << !sum << "\n";
		}else{
			cout << sum << "\n";
		}
	}
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}


	return 0;
}