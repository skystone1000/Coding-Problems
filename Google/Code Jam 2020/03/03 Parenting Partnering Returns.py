# 03 Parenting Partnering Returns (Final got all cases)

def calc(arrRaw):

    arr = []
    for i in range(len(arrRaw)):
        arr.append((arrRaw[i][0], arrRaw[i][1], i))

    arr.sort()
    
    endC = 0
    endJ = 0
    arrRes = []
    
    for start, end, idx in arr:
        if start < endC and start < endJ:
            return "IMPOSSIBLE"
        if start >= endC:
            arrRes.append(('C', idx))
            endC = end
        else:
            arrRes.append(('J', idx))
            endJ = end
    
    res = ''
    
    for c, idx in sorted(arrRes, key=lambda x: x[1]):
        res += c
    
    return res

T = int(input())

for t in range(1, T + 1):
    N = int(input())
    arr = []

    for _ in range(N):
        interval = [int(s) for s in input().split(" ")]
        arr.append(interval)

    res = calc(arr)
    print("Case #{}: {}".format(t, res))