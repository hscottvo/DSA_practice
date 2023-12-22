n = int(input())

scores = [int(i) for i in input().split()]

one_dict = {}
two_dict = {}
ret = set()

for idx_i, i in enumerate(scores):
    for idx_j, j in enumerate(scores):
        if idx_i == idx_j:
            continue
        # print(f"pair {i} and {j}")
        val = i + j
        pair = tuple(sorted((idx_i, idx_j)))
        if -val not in two_dict:
            two_dict[-val] = [pair]
        else:
            if pair not in two_dict[-val]:
                two_dict[-val].append(pair)

for idx_i, i in enumerate(scores):
    if i not in two_dict:
        continue
    for j in two_dict[i]:
        if idx_i in j:
            continue
        # print(f"{idx_i} matches with", end=" ")
        # print(j[0], "and", j[1])
        ret.add(tuple(sorted((i, scores[j[0]], scores[j[1]]))))

if len(ret) != 0:
    for i in ret:
        print(i[0], i[1], i[2])
else:
    print("None")
