n = int(input())
a = list(map(int, input().split()))
ans = ['0'] * n
base = 1
sum = 0
for i in range(n):
    sum += a[i] * base
    if sum > 0:
        ans[i] = '+'
    elif sum < 0:
        ans[i] = '-'
    base *= 2
print(''.join(map(str, ans)))