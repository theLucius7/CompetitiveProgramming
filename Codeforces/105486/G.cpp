#include <bits/stdc++.h>

using i64 = long long;
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	cin >> n;
	int a[100092];
	for(int i = 1 ; i<= n ; i++)
	{
		cin >> a[i];
	}
	set<int> q;
	for(int i = 1 ; i< n ; i++)
	{
		int x = a[i],y = a[i+1];
		int z = x|y;
		q.insert(x);
		q.insert(y);
		q.insert(z);
		q.insert(x&y);
		q.insert(x^y);
		q.insert(y^z);
		q.insert(x^z);
		q.insert(0);
	}
	cout << q.size() << endl;

	

	return 0;
}