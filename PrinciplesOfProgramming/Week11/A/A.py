def cal(x):
    if x == 0:
        return 1
    else:
        return x * cal(x - 1)

x = input()
y = x[:-1]
print(cal(int(y)))

# 一直WA，为什么？？？