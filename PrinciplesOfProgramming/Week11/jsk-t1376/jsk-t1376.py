value = input().split()

high = int(value[0])
up = int(value[1])
down = int(value[2])

days = 1
while high > 0:
    high -= up
    if high > 0:
        high += down
    else:
        break
    days += 1

print(days)