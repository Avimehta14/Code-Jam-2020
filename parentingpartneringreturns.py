def sortsolve(bet):
    arr = []
    for i in range(len(bet)):
        arr.append((bet[i][0], bet[i][1], i))
    arr.sort()
    print(arr)
    endc = 0                                                                                 
    endj = 0
    res_arr = []
    for st, end, ind in arr:
        print("s=",st)
        if st < endc and st < endj :
            return "IMPOSSIBLE"
        if st >= endc :
            res_arr.append(('C', ind))
            endc = end
        else:
            res_arr.append(('J', ind))
            endj = end
    res = ''
    for a, ind in sorted(res_arr, key = lambda x: x[1]):
        res += a
    return res
t = int(input())
for t in range(1, t + 1):
    n = int(input())
    arr = []
    for _ in range(n):
        vals= [int(s) for s in input().split(" ")]
        arr.append(vals)
    res = sortsolve(arr)
    print("Case #{}: {}".format(t, res))