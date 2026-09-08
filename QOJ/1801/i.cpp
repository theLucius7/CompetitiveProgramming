#include<stdio.h>
#include<string.h>
int p(char word[],int len){
	int a=0;
	if(len==1||word[0]==word[len-1]){
		a=0;
	}else{
		for(int i=0;i<len-1;i++){
			a++;
			if(word[i]==word[i+1]){
				break;
			}
			if(i==len-2)
			a++;
		}
		if(a==len)
			a=-1;
	}
	return a;
}
int main(){
	int n;
	scanf("%d",&n);
	getchar();
	char word[500000];
	for(int i=0;i<n;i++){
		scanf("%s",word);
		int len=strlen(word);
		int k=p(word,len);
		printf("%d\n",k);
	}
	return 0;
}