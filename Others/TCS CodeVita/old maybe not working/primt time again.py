def isPrim(n):
    if n <=1 :
        return False
    if n <=3:
        return True
    else:
        for x in range(3,n):
            if(n%x==0):
                return False
        return True

D,P=map(int,input().split())
H=D/P
N=H
c=0
while N>1:
    i=0
    count=0
    while True:
        if isPrim(int((i*H)+N)) and ((i*H)+N)<=D:
            count=count+1
        if i==(P-1): break
        i+=1
    if count == P: c+=1       
    N-=1
print(c)