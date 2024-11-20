def cal(x, n):
    if n == 1:
        return x / (1 + x)
    else:
        return x / (n + cal(x, n - 1))
    
value = input().split()
x = int(value[0])
n = int(value[1])

print(f"{cal(x, n):.2f}")
