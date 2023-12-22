budget, n = [int(i) for i in input().split()]

out = 0
items = sorted([int(i) for i in input().split()])
# print(items)
for i in items:
    if budget < i:
        break
    budget -= i
    out += 1
print(out)
