#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
using i64 = long long;
using i128 = __int128;
using real = long double;
constexpr int inf = 1E8;

int n,bi,bj;
vector<array<int,4>> ans;



signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	cin >> n >> bi >> bj;
	int x,y;
	cout << "Yes" << "\n";

	int xmin = bi, xmax = bi;
	int ymin = bj, ymax = bj;

	int len = 1;

	x = xmin - 1;
	y = ymin - 1;
	while(x >= 1 && y >= 1 && x <= n && y <= n){
		ans.push_back({x,y,len,len});
		xmin = std::min(xmin, x);
		xmax = std::max(xmax, x + len);
		ymin = std::min(ymin, y);
		ymax = std::max(ymax, y + len);

		len++,x--,y--;
	}
	
	x = xmax + 1;
	y = ymax + 1;
	while(x >= 1 && y >= 1 && x <= n && y <= n){
		ans.push_back({x,y,-len,-len});
		xmin = std::min(xmin, x - len);
		xmax = std::max(xmax, x);
		ymin = std::min(ymin, y - len);
		ymax = std::max(ymax, y);
		len++,x++,y++;
	}


	x = xmax + 1;
	y = ymin - 1;
	while(x >= 1 && y >= 1 && x <= n && y <= n){
		ans.push_back({x,y,-len,len});
		xmin = std::min(xmin, x - len);
		xmax = std::max(xmax, x);
		ymin = std::min(ymin, y);
		ymax = std::max(ymax, y + len);
		len++,x++,y--;
	}

	x = xmin - 1;
	y = ymax + 1;
	while(x >= 1 && y >= 1 && x <= n && y <= n){
		ans.push_back({x,y,len,-len});
		xmin = std::min(xmin, x);
		xmax = std::max(xmax, x + len);
		ymin = std::min(ymin, y - len);
		ymax = std::max(ymax, y);

		len++,x--,y++;
	}

	cout << ans.size() << "\n";
	for(auto [a, b, c, d] : ans){
		cout << a << " " << b << " " << c << " " << d << "\n";
	}
	

	return 0;
}