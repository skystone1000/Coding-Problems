n=int(input())
timings=[]
for _ in range(n):
    a,b = map(int , input().split(' '))
    timings.append([a,a+b])

timings.sort(key = lambda x: x[0])
cnt=1
mx = timings[0][1]
for i in range(1,n):
    if mx>=timings[i][0] :
        cnt+=1 
        mx = max(mx,timings[i][1])
        
print(cnt) 