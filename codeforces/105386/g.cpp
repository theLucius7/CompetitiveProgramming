#include <bits/stdc++.h>

using i64 = long long;

using namespace std;

void solve(){
	int n;
	cin >> n;
	if(n == 1 || n % 4 == 0){
		cout << "impossible" << "\n";
		return;
	}
	std::vector<int> v;
	v.push_back(1);
	v.push_back(0);
	for(int i = 2 ; i< n ; i++){
		if(i % 4 == 3){
			v.push_back(i+1);
			v.push_back(i);
			i++;
		}else{
			v.push_back(i);
		}
	}
	for(int i = 0; i < v.size() ; i++){
		cout << v[i] << " ";
	}
	cout << "\n";
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int T;
	cin >> T;
	while(T--){
		solve();
	}

	return 0;
}