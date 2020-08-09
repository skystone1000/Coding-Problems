A=int(input())
c=list(map(int,input().split()))
B=int(input())
co=skips=0
if(c[-1]<0):
  co=-1
else:
  for i in c:
    if(skips>B):
      break
    else:
      if(i<0):
        skips+=i
        continue
      co+=i
print(co,end='')