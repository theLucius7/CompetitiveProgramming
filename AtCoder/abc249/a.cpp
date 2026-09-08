#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int a, b, c, d, e, f, x;
	cin >> a >> b >> c >> d >> e >> f >> x;
	
	int T, mod, res1 = 0, res2 = 0;
	
	//Takahashi
	T = x / (a + c), mod = x % (a + c);
	res1 += T * a;
	if (mod >= a) res1 += a;
	else res1 += mod;
	res1 *= b;
	
	//Aoki
	T = x / (d + f), mod = x % (d + f);
	res2 += T * d;
	if (mod >= d) res2 += d;
	else res2 += mod;
	res2 *= e;
	
	if (res1 > res2) cout << "Takahashi" << "\n";
	else if (res1 < res2) cout << "Aoki" << "\n";
	else cout << "Draw" << "\n";
	
	return 0;
}