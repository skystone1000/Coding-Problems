n = list(map(int,input().split()))

s=list(map(int,input().split()))

count=0
for i in range(len(s)):
    ran_l = s[i]-n[1]
    ran_u = s[i]+n[1]
    state = 0
    for x in range(len(s)):
        if not (i==x):
            if(ran_l<=s[x]<=ran_u):
                state=1
    count += 1 if(state == 1) else 0
print(count)