#include <bits/stdc++.h>
#define int long long

using i64 = long long;

using namespace std;


void solve(){
	int n,k;
	cin >> n >> k;
	int a[n+1]{};
	int pr[n+1]{};
	int en[n+2]{};
	for(int i = 1; i <= n ; i++){
		cin >> a[i];
		pr[i] = __gcd(pr[i-1],a[i]);
		// cout << pr[i] << endl;
	}
	for(int i = n ; i >= 1 ; i--){
		en[i] = __gcd(en[i+1],a[i]);
		// cout << en[i] << endl;
	}
	int ans = pr[n];

	for(int i = 1 ; i<= n ; i++){
		if(pr[i] != pr[i-1]){
			int gc = pr[i-1];
			for(int j = i ; j <= n ; j++){
				gc = __gcd(gc,a[j] + k);\
				ans = max(ans,__gcd(gc,en[j+1]));
			}
			// break;
		}
	}
	cout << ans << "\n";
}
signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int T;
	cin >> T;
	while(T--){
		solve();
	}

	return 0;
}