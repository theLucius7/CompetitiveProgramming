#include <bits/stdc++.h>

using namespace std;
const int N = 2e5+10;

#define int long long


void solve(){
	int a,b,c;
	cin >> a >> b >> c;
	b -= (b % c);
	if(b <= 0){
		cout << "Alice" << "\n";
		return ;
	}
	a -= (a % c);
	if(a <= 0){
		cout << "Bob" << "\n";
		return ;
	}
	cout << "Lasting Battle" << "\n";
}
signed main(){
	int T;
	T = 1;
	cin >> T;
	while(T--){
		solve();
	}
}