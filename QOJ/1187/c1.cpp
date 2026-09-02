#include <bits/stdc++.h>

using i64 = long long;

using namespace std;

#define int long long

void solve() {
	int n;
	std::cin >> n;

	std::string s, t;
	std::cin >> s >> t;
	if(s != t && s.size() == 1){
		cout << 0 << "\n";
		return;
	}
	s = " " + s;
	t = " " + t;
	if(s == t){
		cout << n*(n+1)/2 << "\n";
	}
	int l = 0;
	int r = 0;
	int ll = 0;
	int rr = 0;
	bool f = true;
	for(int i = 1 ; i <= n ; i++){
		if(s[i] != t[i]){
			if(l == 0){
				l = i;
				int id = i+1;
				while(id<= n && s[id] != t[id]){
					id++;
				}
				id--;
				r =id;
				i = id;
			}else if(ll == 0){
				ll = i;
				int id = i+1;
				while(id<= n && s[id] != t[id]){
					id++;
				}
				id--;
				rr  =id;
				i = id;
			}else{

				f = false;
			}
		}
	}
	if(!f ){
		cout << 0 << "\n";
	}else if(l !=0 && ll == 0){
		
		cout << (r-l) * 2+ max((int)0,n-r)*2 + max((int)0,l - 1)*2 << "\n";

	}else if(l !=0 && ll !=0){
		cout << 6  << "\n";
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