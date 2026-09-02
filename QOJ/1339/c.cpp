#include <bits/stdc++.h>

using i64 = long long;

using namespace std;
#define int long long
const int N = 1e5+10;
struct node
{
	string s;
	int v,k;
}e[N];
void solve() {
	int n;
	cin >> n;
	int cnt = n *512;
	for(int i = 1 ; i<= n;i++){
		cin >> e[i].s >> e[i].v ;
		if(e[i].s != "add"){
			cin >> e[i].k;
		}
	}
	int num = 0;
	int id = 1;
	while(1){
		if(id > n){
			cout << "Yes" << "\n";
			return;
		}
		if(e[id].s == "add"){
			num = (num + e[id].v) % 256;
			id++;
			cnt--;
		}else if(e[id].s == "beq"){
			if(num == e[id].v){
				id = e[id].k;
			}else{
				id++;
			}
			cnt--;
		}else if(e[id].s == "bne"){
			if(num != e[id].v){
				id = e[id].k;
			}
			else{
				id++;
			}
			cnt--;
		}
		else if(e[id].s == "blt"){
			if(num < e[id].v){
				id = e[id].k;
			}
			else{
				id++;
			}
			cnt--;
		}
		else if(e[id].s == "bgt"){
			if(num > e[id].v){
				id = e[id].k;
			}
			else{
				id++;
			}
			cnt--;
		}
		if(cnt == 0){
			break;
		}
	}
	cout << "No" << "\n";

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