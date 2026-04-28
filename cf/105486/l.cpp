#include <bits/stdc++.h>

using i64 = long long;
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);


	int n;
	n = 100;
	int a[100009];
	int b,c,d;
	cin >> b >> c >> d;
	cout << 100 << endl;
	for(int i = 1 ; i<= 50; i++)
	{
		cout << b << " ";
	}
	for(int i = 51; i<= 95 ;i++)
	{
		cout << c <<" ";
	}
	for(int i = 96;i<= 99 ;i++) cout << d << " ";
	cout << d+1 << endl;

	return 0;
}