p=input("")
q=input("")
p=list(p.split(" "))
q=list(q.split(" "))
for t in range(0,len(q)-1):
    c=[0 for i in range(t,len(q))]
    for i in p:
        for j in range(len(q)):
            k=0
            while(k<len(p)):
                if(p[k]==q[j]):
                       c[j]+=1
                       for m in range(k+1,len(i)):
                           if(i[m] not in q):
                                  k=m-1
                           elif(i[m-1]==i[m]):
                                  k=m-1
                k+=1
    m1=max(c)
    if(c.count(m1)>1):
       m2=c.index(m1)
       for i in range(m2,len(c)):
           if(c[i]==m1):
               if(ord(q[i])<ord(q[m2])):
                  m2=i
    else:
        m2=c.index(m1)
    q[m2],q[t]=q[t],q[m2]
print("".join(q))