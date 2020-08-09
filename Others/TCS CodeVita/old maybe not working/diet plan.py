limit=input().split()
items=input().split("|")
d={}
for i in limit:
    d[i[-1]]=int(i[:-1])
l=[]
for j in items:
    k=j.split()
    d1={}
    for i in k:
        d1[i[-1]]=int(i[:-1])
    l.append(d1)
P,C,F=0,0,0
for i in l:
    P+=i['P']
    C+=i['C']
    F+=i['F']
value=0
for i in range(min(d.values())):
    if(d['P']<i*P or d['C']<i*C or d['F']<i*F):
        value=i-1
        break
l1=[]
P1,C1,F1=0,0,0
for i in l:
    l1.append((i['P'],i['C'],i['F']))
    for j in l[1:]:
        P1=i['P']+j['P']
        C1=i['C']+j['C']
        F1=i['F']+j['F']
        l1.append((P1,C1,F1))
l2=[]
for i in l1:
    if(d['P']>(P*value)+i[0] and d['C']>(C*value)+i[1] and d['F']>(F*value)+i[2]):
        l2.append((d['P']-((P*value)+i[0]),d['C']-((C*value)+i[1]),d['F']-((F*value)+i[2])))
minj=l2[0][0]
mink=l2[0][1]
minl=l2[0][2]
for j in l2:
    if j[0]<=minj:
        result=j
        if j[1]<=mink:
            result=j
            if j[2]<=minl:
                result=j
                minj=j[0]
                mink=j[1]
                minl=j[2]
    else:
        result=j
#print(" ".join([str(i) for i in result]).strip())
for i in result:
 print(i,end=" ")