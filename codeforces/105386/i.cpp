#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n;
	string s;
	cin >> s;
	std::vector<pair<char,int>> v;
	for(int i = 0 ;i < s.size() ; i++){
		int j = i + 1;
		while(s[i] == s[j]) j++;
		v.push_back(make_pair(s[i],j-i));
		i = j - 1;
	}
	if(v.size() == 1){
		cout << s.size() / 2 << "\n";
		return;
	}
	if(v[0].first == v.back().first){
		v[0].second += v.back().second;
		v.pop_back();
	}
	int ans = 0;
	int f = 0;
	for(auto[c,num] : v){
		ans += num/2;
		if(num % 2 == 0){
			f = 1;
		}
	}
	cout << ans - f << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}


	return 0;
}