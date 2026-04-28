#include <bits/stdc++.h>

using namespace std;
const int N = 1e6+10;

#define int long long
int a[N],ans[N];
void solve(){
	int n;
	std::cin >> n;
	for(int i = 1 ; i<= n ;i++){
		cin >> a[i];
	}
	if(n <= 2){
		cout << -1 << "\n";
		return ;
	}
	if(n == 3){
		if(a[1] == 1 && a[2] == 2 && a[3] == 3){
			cout << 3 << " " << 1 << " " << 1 << "\n";
		}
		else if(a[1] == 1 && a[2] == 3 && a[3] == 2){
			cout << 2 << " " << 1 << " " << 1 << "\n";
		}
		if(a[1] == 2 && a[2] == 1 && a[3] == 3){
			cout << 3 << " " << 3 << " " << 2 << "\n";
		}
		if(a[1] == 2 && a[2] == 3 && a[3] == 1){
			cout << 1 << " " << 1 << " " << 2 << "\n";
		}
		if(a[1] == 3 && a[2] == 2 && a[3] == 1){
			cout << 1 << " " << 1 << " " << 3 << "\n";
		}
		else if(a[1] == 3 && a[2] == 1 && a[3] == 2){
			cout << 2 << " " << 3 << " " << 3<< "\n";
		}else{
			cout << -1 << "\n";
		}
		return;
	}
	for(int i = 1 ; i<= n ; i++){
		ans[i] = n;
	}
	if(a[1] == n || a[n] == n){
		if(a[1] == n){
			if(a[2] == n-1) a[1] = n-2;
			else a[1] = n-1;
		}else{
			if(a[n-1] == n-1){
				a[n] = n-2;
			}else{
				a[n] = n-1;
			}
		}
		for(int i = 1 ;i <= n ; i++){
			cout << a[i] << " ";
		}
		cout << "\n";
		return ;
	}
	for(int i = 1 ; i<= n ; i++){
		if(a[i] == n){
			for(int j = n -1; j >= 1 ; j--){
				if(a[i-1] != j && a[i+1] != j){
					ans[i] = j;
					break;
				}
			}
			break;
		}
	}
	for(int i = 1 ; i<= n ; i++){
		cout << ans[i] << " ";
	}
	cout << "\n";

}
signed main(){
	int T;
	T = 1;
	cin >> T;
	while(T--){
		solve();
	}
}