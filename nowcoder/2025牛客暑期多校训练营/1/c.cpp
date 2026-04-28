#include<bits/stdc++.h>
using namespace std;
#define maxnum 10000051
bool Isprim[maxnum];
int  primes[maxnum];
 
int main(){
    unsigned long long nums = 1, n = 0,count_prime = 0,temp = 0;
    scanf("%lld",&n);
    memset(Isprim,1,sizeof(Isprim));
    Isprim[1] = false;
    for(unsigned long long i = 2;i<=n;i++){
        if(Isprim[i]){
            primes[count_prime] = i;
            count_prime++;
        }
        for(unsigned long long j = 0;j<count_prime&&(temp = primes[j]*i)<=n;j++){
            Isprim[temp] = false;
            if(i%primes[j]==0){
                break;
            }
        }
    }
 
    for(unsigned long long i = 0;i<count_prime;i++){
        unsigned long long emm = 1;
        while(emm<=n){//通过循环让emm从1开始不断乘以质数直到大于输入的数字n
            emm *= primes[i];//这时候让emm除以该质数就可以得到小于等于n的数
        }
        emm /= primes[i];
        primes[i] = emm;
    }
    for(unsigned long long i = 0;i<count_prime;i++){
        nums = nums*primes[i]%1000000007;
    }
    printf("%llu\n",nums);
    return 0;
}