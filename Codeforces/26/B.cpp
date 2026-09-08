#include<cstdio>
using namespace std;

int main()
{
	register int ans=0,cnt=0;
	register char c=getchar();
	while(c!='\n'&&c!=EOF)
	{
		if(c=='(')  cnt++;
		else  if(cnt>0)  ans+=2,cnt--;
		c=getchar();
	}
	printf("%d",ans);
	return 0;
}