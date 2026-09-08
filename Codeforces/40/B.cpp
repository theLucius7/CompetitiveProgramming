#include<bits/stdc++.h>
using namespace std;
int n, m, x;//定义行，列与次数的信息
signed main()
{
	cin >> n >> m >> x;
	if(n - (2 * x - 1) < 0 || m - (2 * x - 1) < 0)
   	//对结论进行分类讨论，判断没有格子会被涂x次的情况
	{
		cout << 0;
		return 0;
	}
	n -= 2 * x - 1, m -= 2 * x - 1;//在计算第二种情况时，我们要先减后判断
	cout << max(n + m, 1);//当总次数大于一时，输出n + m,否则输出一
	return 0;
}