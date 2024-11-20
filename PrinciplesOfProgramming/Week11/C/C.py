inp = input()
inp = inp.split()

a = int(inp[0])
b = int(inp[1])

result = 1
for i in range(b):
    result = result * a % 1000

print(str(result).zfill(3))