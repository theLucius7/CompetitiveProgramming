#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	
	int time1 = b * 60 + a * 3600, time2 = d * 60 + 1 + c * 3600;
	
	if (time1 < time2) cout << "Takahashi" << "\n";
	else cout << "Aoki" << "\n";
	
	return 0;
}