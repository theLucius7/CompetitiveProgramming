#include <bits/stdc++.h>

#define x first
#define y second

constexpr int INF = 0x7f7f7f7f7f7f7f7f;

using i64 = long long;

void solve () {
	int n;
	std::cin >> n;
	
	std::vector <std::string> p;
	std::vector <int> a;
	
	std::unordered_map <std::string, int> mp; 
	
	for (int i = 0; i < n; i ++ ) {
		std::string s;
		std::cin >> s;
		
		int x;
		std::cin >> x;
		
		p.push_back (s);
		a.push_back (x);
		
		mp[s] += x;
	} 
	
	int maxn = 0; 
	for (int i = 0; i < n; i ++ ) {
		maxn = std::max (maxn, mp[p[i]]);
	}
	
	std::unordered_map <std::string, int> hash;
	
	std::string name;
	
	for (int i = 0; i < n; i ++ ) {
		hash[p[i]] += a[i];
		if (mp[p[i]] == maxn && hash[p[i]] >= maxn) {
			name = p[i];
			break;
		}
	} 
	
	std::cout << name << "\n";
}

int main () {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	solve (); 
	
	return 0;
} 