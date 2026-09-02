#include <bits/stdc++.h>
#define int long long 
using namespace std;
using i64 = long long;


void solve() {
	int n, q;
	cin >> n >> q;
	int a[100009];
	for(int i = 1 ; i<= n ; i++)
	{
		cin >> a[i];
	}
	while(q--)
	{
		int k;
		cin >> k;
		if(k * a[n]*n <= 1e6)
		{
			int num = 0;
			for(int i = k*a[n]+1 ; i>= 1;i--)
			{
				int x = i;
				int sum = 0;
				for(int j = n ; j> 1 ; j--){
					sum += x/a[j];
					x = x%a[j];
				}
				sum += x;
				if(sum == k)
				{
					cout << i <<' ';
					num++;
				}
			}
			cout << num << ' ';
		}
		else cout << a[n] << ' ';
	}
	
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	// std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}